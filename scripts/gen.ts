import { exec, ARGV } from "./shared";
import fs from "fs/promises";
import chalk from "chalk";

async function getSha(fname: string) {
  return (
    (await exec(`sha256sum src/problems/${fname}/gen.cpp`)).stdout.split(
      " "
    )[0] +
    (await exec(`sha256sum src/problems/${fname}/sol.cpp`)).stdout.split(" ")[0]
  );
}

export default async function cpp() {
  const items = (await exec("ls src/problems")).stdout
    .split("\n")
    .filter((l) => l.length > 0);

  let buildinfo: { [statement: string]: string } = {};
  try {
    if (!ARGV.includes("--new"))
      buildinfo = JSON.parse((await fs.readFile(".buildinfo_gen")).toString());
    else console.log("--new specified, recompiling all files");
  } catch (err) {
    buildinfo = {};
  }

  let done = 0;
  const total = items.length;

  async function compile(fname: string, skip: boolean) {
    if (skip) {
      done++;
      console.log(chalk.cyan(`Skipped ${fname} [${done}/${total}]`));
      return;
    }

    await exec(`src/build.sh ${fname}`);
    done++;
    console.log(chalk.green(`Compiled ${fname} [${done}/${total}]`));
  }

  console.log(`Start building ${total} tasks (${items})`);

  const promises = [];
  for (const item of items) {
    const sha = await getSha(item);
    if (buildinfo[item] == sha) {
      promises.push(compile(item, true));
      continue;
    }

    buildinfo[item] = sha;
    promises.push(compile(item, false));
  }

  Promise.all(promises);

  await fs.writeFile(".buildinfo_gen", JSON.stringify(buildinfo, null, 4));
}
