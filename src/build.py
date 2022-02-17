import os
from typing import Callable

from lib.genutils import getGenerator
from problems.aplusb.gen import useGenerator as aplusb
from problems.calculus_wtf.gen import useGenerator as calculus_wtf

assert("stupid-problems" in os.popen("pwd").read())


def build(name: str, user: Callable):
    """Build testcase for a given statement

    Args:
        name (str): Name of Statement, **must match its folder name**
        user (function): useGenerator function
    """
    user(getGenerator(name))
    os.system(f"mkdir -p problems/{name} && rm -rf problems/{name}/testcase")
    os.system(f"mv src/problems/{name}/testcase problems/{name}")


build("aplusb", aplusb)
build("calculus_wtf", calculus_wtf)
