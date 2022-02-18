import chalk from "chalk";

import { exec, ARGV, getStatements } from "./shared";

import fs from "fs/promises";

function getCommand(fname: string) {
  return `cd statements && xelatex ${fname}.tex && mv ${fname}.pdf ../dist-web/pdf`;
}

async function getSha(fname: string) {
  return (await exec(`cd statements && sha256sum ${fname}.tex`)).stdout.split(
    " "
  )[0];
}

export default async function statements() {
  const statements = await getStatements();

  let buildinfo: { [statement: string]: string } = {};
  try {
    if (!ARGV.includes("--new"))
      buildinfo = JSON.parse(
        (await fs.readFile(".buildinfo_statement")).toString()
      );
    else console.log("--new specified, recompiling all files");
  } catch (err) {
    buildinfo = {};
  }

  const clean = (fname: string) =>
    `cd statements && ${["aux", "fdb*", "fls", "log", "gz", "xdv", "out", "pdf"]
      .map((ext) => `rm -f ${fname}.${ext}`)
      .join("&&")}`;

  console.log(`Will compile ${statements.length} statements (${statements})`);

  let failureExists = false;

  await exec("mkdir -p dist-web/pdf");
  await exec(clean("*"));
  console.log("Prebuild Cleaned");
  for (const [index, statement] of Object.entries(statements)) {
    const progress = `${statement} [${+index + 1}/${statements.length}]`;

    const sha = await getSha(statement);
    if (buildinfo[statement] == sha) {
      console.log(chalk.cyan(`Skipped ${progress}`));
      continue;
    }

    try {
      await Promise.race([
        exec(getCommand(statement)),
        new Promise((res, rej) => setTimeout(() => rej(), 3000)),
      ]);

      buildinfo[statement] = sha;
      console.log(chalk.green(`Compiled ${progress}`));
      await exec(clean(statement));
    } catch (err) {
      failureExists = true;
      console.log(chalk.red(`FAILED (TIMEOUT) ${progress}`));
    }
  }

  await fs.writeFile(
    ".buildinfo_statement",
    JSON.stringify(buildinfo, null, 4)
  );

  if (ARGV.includes("--open")) {
    // * This command is not universal, but it works for me!
    // * Also opening explorer.exe throws error, idk why, microsoft?
    await exec(`cd dist-web/pdf && explorer.exe .`).catch((e) => {});
  }

  process.exit(failureExists ? 1 : 0);
}
