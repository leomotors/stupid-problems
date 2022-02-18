// @ts-check

import statements from "./statements";
import web from "./web";

const buildTargets = {
  statements,
  web,
};

function main() {
  buildTargets[process.argv[2] as keyof typeof buildTargets]?.();
}

main();
