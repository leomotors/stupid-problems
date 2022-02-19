import os
import sys

from typing import Callable

from lib.genutils import getGenerator

from importlib import import_module

# ? Only run this file via yarn problem
# ? yarn will always execute this from root dir, which is very good!
assert("stupid-problems" in os.popen("pwd").read())


def build(name: str, user: Callable, solonly: bool):
    """Build testcase for a given statement

    Args:
        name (str): Name of Statement, **must match its folder name**
        user (Callable): useGenerator function
        solonly (bool): Do not generate test case, use old one
    """
    user(getGenerator(name, solonly))
    os.system(f"mkdir -p problems/{name}/testcase")
    if not solonly:
        os.system(f"rm -rf problems/{name}/testcase/*")
    os.system(f"mv src/problems/{name}/testcase/* problems/{name}/testcase")
    os.system(f"cp src/problems/{name}/manifest.json problems/{name}")


if len(sys.argv) > 1:
    problems = sys.argv[1:]
    asserter = os.listdir("src/problems")
else:
    problems = os.listdir("src/problems")
    asserter = problems[:]

solonly = False
if len(sys.argv) > 2:
    if sys.argv[2] == "sol":
        solonly = True


for problem in problems:
    if problem not in asserter:
        if problem != "sol":
            print(f"[WARN] {problem} not available")
        continue

    print(f"\u001b[36m<========== BUILDING FOR {problem} ==========>\u001b[0m")
    module = import_module(f"problems.{problem}.gen", "src")
    build(problem, module.useGenerator, solonly)
