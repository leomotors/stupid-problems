
from random import randint, seed

# * args: [0,a) range, [0,b) range


def f(t):
    return f"0{t}" if t < 10 else f"{t}"


def useGenerator(gen):
    seed(69420)
    for i in range(1, 25+1):
        gen(f"1-{f(i)}", 1, 10**18)

    for i in range(26, 50+1):
        gen(f"1-{f(i)}", 10**18, 1)

    for i in range(1, 50+1):
        gen(f"2-{f(i)}", randint(1, 10), randint(1, 10))

    for i in range(1, 50+1):
        gen(f"3-{f(i)}", randint(1, 10**9), randint(1, 10**9))

    for i in range(1, 50+1):
        gen(f"4-{f(i)}", randint(1, 10**18), randint(1, 10**18))
