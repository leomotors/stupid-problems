import os
import time


def gen(id, seed):
    print(f"Generating Test Case {id}")
    os.system(f"./gen {seed} > tc/{id}.in")
    print(f"Running Test Case {id}")
    t = time.time()
    os.system(f"cat tc/{id}.in | ./sol > tc/{id}.out")
    print(
        f"Finished Test Case {id} in {round((time.time() - t) * 1000, 3)} ms")


gen(1, "112 ติดบั๊ก")
gen(2, 69)
gen(3, 420)
gen(4, 69420)
gen(5, 177013)
gen(6, "germany")
gen(7, "jail")
gen(8, "bruh wtf")
gen(9, "meta")
gen(10, 101336844)
