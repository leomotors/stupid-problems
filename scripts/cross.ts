import { exec, ARGV } from "./shared";
import fs from "fs/promises";
import chalk from "chalk";
import { assert } from "console";

function min(a: number, b: number) {
  return a > b ? b : a;
}

function diffChecker(expected: string, actual: string) {
  const etoken = expected.split(/\s+/);
  const atoken = actual.split(/\s+/);

  for (let i = 0; i < min(etoken.length, atoken.length); i++) {
    if (etoken[i] !== atoken[i]) {
      console.log(
        chalk.yellow(
          `Check Failed: At token #${i + 1}: Expected ${
            etoken[i]
          } but received ${atoken[i]}`
        )
      );
    }
    return false;
  }

  if (etoken.length != atoken.length) {
    console.log(
      chalk.yellow(
        `Check Failed: Expected output to has ${etoken.length} tokens but received ${atoken.length}`
      )
    );
  }

  return false;
}

export default async function cross() {
  const argv = ARGV.split(" ");
  const problem = argv[0];
  const crossname = argv[1];

  assert(problem);
  assert(crossname);

  const files = await fs.readdir(`./problems/${problem}/testcase`);
  const inputs = files.filter((fname) => fname.endsWith(".in"));

  for (const input of inputs) {
    const output = (
      await exec(
        `cat ./problems/${problem}/testcase/${input} | ./src/problems/${problem}/${crossname}`
      )
    ).stdout;

    const expected = (
      await fs.readFile(
        `./problems/${problem}/testcase/${input
          .split(".")
          .slice(0, -1)
          .join(".")}.out`
      )
    ).toString();

    if (diffChecker(expected, output)) {
      console.log(chalk.red(`Check failed at ${input}`));
      return 1;
    }
  }

  console.log(
    chalk.green(`All ${inputs.length} testcases matches the cross checker!`)
  );

  return 0;
}
