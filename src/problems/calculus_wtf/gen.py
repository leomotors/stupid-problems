import os
import time

# * T<=11, n<=10, c_i<=10
# * มีชุดทดสอบ 10 ชุด ชุดละ 10 คะแนน
# * 10 คะแนน: f(x) = ax^2 + c
# * 10 คะแนน: f(x) = ax^2 + bx + c
# * 30 คะแนน: T<=4, n<=3
# * 50 คะแนน: ไม่มีเงื่อนไขเพิ่มเติม


def gen(id, seed, T, n):
    print(f"Generating Test Case {id}")
    os.system(f"./gen {T} {n} {seed} > tc/{id}.in")
    print(f"Running Test Case {id}")
    t = time.time()
    os.system(f"cat tc/{id}.in | ./sol > tc/{id}.out")
    print(
        f"Finished Test Case {id} in {round((time.time() - t) * 1000, 3)} ms")


gen("s1", "sample1", 2, 2)
gen("s2", "ssss", 3, 2)
gen(1, "deg 2 pls", 2, 2)
gen(2, "seed", 3, 2)
gen(3, "cocoa", 4, 3)
gen(4, "chino", 4, 3)
gen(5, "rize", 4, 3)
gen(6, "germany", 6, 10)
gen(7, "jail", 7, 8)
gen(8, "bruh wtf", 7, 9)
gen(9, "meta", 8, 10)
gen(10, 101336844, 11, 10)
