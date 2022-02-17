// @ts-check

import chalk from "chalk";

import { exec as execCb } from "child_process";
import { promisify } from "util";
import fs from "fs/promises";

const exec = promisify(execCb);

const buildTargets = {
  statements,
  web,
};

const ARGV = process.argv.slice(3).join(" ");

buildTargets[process.argv[2]]?.();

// * END OF MAIN, BELOW ARE FUNCTIONS

/**
 * @param {string} fname
 * @returns {string}
 */
function getCommand(fname) {
  return `cd statements && xelatex ${fname}.tex && mv ${fname}.pdf ../dist-web/pdf`;
}

/**
 * @param {string} fname
 * @returns {Promise<string>}
 */
async function getSha(fname) {
  return (await exec(`cd statements && sha256sum ${fname}.tex`)).stdout.split(
    " "
  )[0];
}

async function statements() {
  /** @type {{[statement: string]: string}} */
  let buildinfo = {};
  try {
    if (!ARGV.includes("--new"))
      buildinfo = JSON.parse((await fs.readFile(".buildinfo")).toString());
    else console.log("--new specified, recompiling all files");
  } catch (err) {
    buildinfo = {};
  }

  /**
   * @param {string} fname
   * @returns {string}
   */
  const clean = (fname) =>
    `cd statements && ${["aux", "fdb*", "fls", "log", "gz", "xdv", "out"]
      .map((ext) => `rm -f ${fname}.${ext}`)
      .join("&&")}`;

  const statements = (await exec("ls statements")).stdout
    .split("\n")
    .filter((fname) => fname.endsWith(".tex"))
    .map((fname) => fname.split(".tex")[0]);

  console.log(`Will compile ${statements.length} statements (${statements})`);

  let failureExists = false;

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

  await fs.writeFile(".buildinfo", JSON.stringify(buildinfo, null, 4));

  if (ARGV.includes("--open")) {
    // * This command is not universal, but it works for me!
    // * Also opening explorer.exe throws error, idk why, microsoft?
    await exec(`cd dist-web/pdf && explorer.exe .`).catch((e) => {});
  }

  process.exit(failureExists ? 1 : 0);
}

async function web() {
  await exec("cp web/* dist-web");
}
