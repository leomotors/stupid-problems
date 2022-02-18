import os
from typing import Callable

from lib.genutils import getGenerator

from importlib import import_module

assert("stupid-problems" in os.popen("pwd").read())


def build(name: str, user: Callable):
    """Build testcase for a given statement

    Args:
        name (str): Name of Statement, **must match its folder name**
        user (Callable): useGenerator function
    """
    user(getGenerator(name))
    os.system(f"mkdir -p problems/{name} && rm -rf problems/{name}/testcase")
    os.system(f"mv src/problems/{name}/testcase problems/{name}")
    os.system(f"cp src/problems/{name}/manifest.json problems/{name}")


problems = os.listdir("src/problems")

for problem in problems:
    print(f"\u001b[36m<========== BUILDING FOR {problem} ==========>\u001b[0m")
    module = import_module(f"problems.{problem}.gen", "src")
    build(problem, module.useGenerator)
