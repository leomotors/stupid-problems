import os
import time


def getGenerator(name: str):
    root = f"src/problems/{name}"

    def gen(id, seed, *args):
        args = " ".join(str(a) for a in args)
        print(f"Generating Test Case {id}")
        os.system(f"mkdir -p {root}/testcase")
        os.system(f"{root}/gen {args} {seed} > {root}/testcase/{id}.in")
        print(f"Running Test Case {id}")
        t = time.time()
        os.system(
            f"cat {root}/testcase/{id}.in | {root}/sol > {root}/testcase/{id}.out")
        print(
            f"Finished Test Case {id} in {round((time.time() - t) * 1000, 3)} ms")
    return gen
