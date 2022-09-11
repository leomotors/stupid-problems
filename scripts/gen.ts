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
    .filter((l) => l.length > 0 && !l.includes("."));

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

  async function compile(fname: string, skip: boolean, succ?: () => void) {
    if (skip) {
      done++;
      console.log(chalk.cyan(`Skipped ${fname} [${done}/${total}]`));
      return;
    }

    // * Build Interactive
    let arg = "";

    try {
      const folders = (await exec(`ls src/problems/${fname}`)).stdout.split(
        "\n"
      );
      if (folders.includes("private")) arg = "private";
      else if (folders.includes("public")) arg = "public";

      const res = await exec(`src/build.bash ${fname} ${arg}`);
      done++;
      if (res.stderr) {
        console.log(
          chalk.red(`Compiled FAIL or WARN ${fname} [${done}/${total}]`)
        );
        console.log(res.stderr);
        return;
      }

      succ && succ();

      console.log(chalk.green(`Compiled ${fname} [${done}/${total}]`));
    } catch (err) {
      console.log(chalk.red(`Build ${fname} fail with error: ${err}`));
    }
  }

  console.log(`Start building ${total} tasks (${items})`);

  const promises = [];
  for (const item of items) {
    const sha = await getSha(item).catch((e) => {
      console.log(`Will skip ${item} because it throws ${e}`);
      done++;
    });

    if (!sha) continue;

    if (buildinfo[item] == sha) {
      promises.push(compile(item, true));
      continue;
    }

    promises.push(
      compile(item, false, () => {
        buildinfo[item] = sha;
      })
    );
  }

  await Promise.all(promises);
  await fs.writeFile(".buildinfo_gen", JSON.stringify(buildinfo, null, 4));

  return 0;
}
