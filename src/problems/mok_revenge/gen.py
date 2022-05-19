
from random import randint, seed, random

# * args = N P xr


def f(t):
    return f"0{t}" if t < 10 else f"{t}"


def useGenerator(gen):
    seed(69420)

    for t in range(1, 12+1):
        gen(f"1-{f(t)}", randint(70, 100), randint(1, 220), randint(70, 100))

    for t in range(1, 3+1):
        gen(f"2-{f(t)}", randint(1_000_000, 6_000_000),
            int(pow(10, random()) * 7), int(pow(10, random()) * 6))

    for t in range(1, 4+1):
        gen(f"3-{f(t)}", randint(20_000, 100_000),
            int(pow(10, random()*18)), int(pow(10, random()*18)))

    for t in range(1, 3+1):
        gen(f"4-{f(t)}", 6 * int(pow(10, random() * 6)),
            1, int(pow(10, random() * 18)))

    gen(f"4-04", 6_000_000,
        1, int(pow(10, random() * 18)))

    for t in range(1, 50+1):
        gen(f"5-{f(t)}", 2,
            int(pow(10, random() * 18)), int(pow(10, random() * 18)))

    for t in range(1, 3+1):
        gen(f"6-{f(t)}", int(pow(10, random() * 6)),
            int(pow(10, random() * 18)), int(pow(10, random() * 18)))

    gen(f"6-04", 1_000_000,
        int(pow(10, random() * 18)), int(pow(10, random() * 18)))

    for t in range(1, 2+1):
        gen(f"7-{f(t)}", 6 * int(pow(10, random() * 6)),
            int(pow(10, random() * 18)), int(pow(10, random() * 18)))

    gen(f"7-03", 6_000_000, 10**18, 10**18)
