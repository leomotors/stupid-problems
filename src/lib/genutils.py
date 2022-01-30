import os
import time


def getGenerator(input: str, output: str):
    def gen(id, seed, *args):
        args = args.join(" ")
        print(f"Generating Test Case {id}")
        os.system(f"{input}/gen {args} {seed} > {output}/{id}.in")
        print(f"Running Test Case {id}")
        t = time.time()
        os.system(f"cat {output}/{id}.in | ./sol > {input}/{id}.out")
        print(
            f"Finished Test Case {id} in {round((time.time() - t) * 1000, 3)} ms")
    return gen
