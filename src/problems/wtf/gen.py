import os
import time

# * C <= 100000, O <= 100000
# * 10 คะแนน : C <= 10, O <= 10
# * 20 คะแนน : C <= 100, O <= 10
# * 20 คะแนน : O <= 100
# * 20 คะแนน : O <= 5000
# * 30 คะแนน : ไม่มีเงื่อนไขเพิ่มเติม


def gen(id, seed):
    print(f"Generating Test Case {id}")
    os.system(f"./gen {seed} > tc/{id}.in")
    print(f"Running Test Case {id}")
    t = time.time()
    os.system(f"cat tc/{id}.in | ./sol > tc/{id}.out")
    print(
        f"Finished Test Case {id} in {round((time.time() - t) * 1000, 3)} ms")


gen(1, "Cocoa")
gen(2, "Chino")
gen(3, "Rize")
gen(4, "Chiya")
gen(5, "Sharo")
gen(6, "Daydream Cafe")
gen(7, "No Poi!")

gen(8, "Tenkuu Cafeteria")
gen(9, "Sekai ga Cafe ni Natchatta")
gen(10, "Nikkori Cafe no Mahou Tsukai")
