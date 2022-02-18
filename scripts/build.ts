import statements from "./statements";
import web from "./web";
import gen from "./gen";

const buildTargets = {
  statements,
  web,
  gen,
};

function main() {
  buildTargets[process.argv[2] as keyof typeof buildTargets]?.();
}

main();
