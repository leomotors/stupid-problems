// @ts-check

import chalk from "chalk";

import { exec as execCb } from "child_process";
import { promisify } from "util";

const exec = promisify(execCb);

const buildTargets = {
  statements,
  web,
};

buildTargets[process.argv[2]]?.();

/**
 * @param {string} fname
 * @returns {string}
 */
function getCommand(fname) {
  return `cd statements && xelatex ${fname}.tex && mv ${fname}.pdf ../dist-web/pdf`;
}

async function statements() {
  const clean = `cd statements && ${[
    "aux",
    "fdb*",
    "fls",
    "log",
    "gz",
    "xdv",
    "out",
  ]
    .map((ext) => `rm -f *.${ext}`)
    .join("&&")}`;

  const statements = (await exec("ls statements")).stdout
    .split("\n")
    .filter((fname) => fname.endsWith(".tex"))
    .map((fname) => fname.split(".tex")[0]);

  console.log(`Will compile ${statements.length} statements (${statements})`);

  await exec(clean);
  console.log("Prebuild Cleaned");
  for (const [index, statement] of Object.entries(statements)) {
    const res = await exec(getCommand(statement));
    console.log(
      chalk.green(`Compiled ${statement} [${+index + 1}/${statements.length}]`)
    );
  }
  await exec(clean);
  console.log("Postbuild Cleaned");

  if (process.argv.slice(3).join("").includes("--open")) {
    // * This command is not universal, but it works for me!
    // * Also opening explorer.exe throws error, idk why, microsoft?
    await exec(`cd dist-web/pdf && explorer.exe .`).catch((e) => {});
  }
}

async function web() {
  await exec("cp web/* dist-web");
}
