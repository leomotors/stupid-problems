import { exec as execCb } from "child_process";
import { promisify } from "util";
export const exec = promisify(execCb);
export const ARGV = process.argv.slice(3).join(" ");

export async function getStatements() {
  return (await exec("ls statements")).stdout
    .split("\n")
    .filter((fname) => fname.endsWith(".tex"))
    .filter((fname) => !fname.startsWith("_"))
    .map((fname) => fname.split(".tex")[0]);
}
