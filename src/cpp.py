import os

problems = os.listdir("src/problems")


def cppbuild(problem: str):
    print(f"Building generator and solution for {problem}")
    os.system(f"src/build.sh {problem}")


for problem in problems:
    cppbuild(problem)
