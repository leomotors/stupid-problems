
from random import randint, seed, random

# * args = R C chance


def f(t):
    return f"0{t}" if t < 10 else f"{t}"


def useGenerator(gen):
    seed(69420)

    # * SUBTASK 1
    for t in range(1, 9+1):
        gen(f"1-{f(t)}", randint(3, 1000), randint(3, 1000), 1000000)

    gen(f"1-10", 1000, 1000, 1000000)

    # * SUBTASK 2
    for t in range(1, 7+1):
        gen(f"2-{f(t)}", randint(3, 150),
            randint(3, 150), randint(500_000, 900_000))

    for t in range(8, 10+1):
        gen(f"2-{f(t)}", 150, 150, randint(500_000, 900_000))

    # * SUBTASK 3
    for t in range(1, 3+1):
        gen(f"3-{f(t)}", randint(3, 1_000),
            randint(3, 1_000), randint(500_000, 900_000))

    gen(f"3-04", 1_000, 1_000, 500_000)
    gen(f"3-05", 1_000, 1_000, 800_000)

    # * SUBTASK 4
    for t in range(1, 3+1):
        gen(f"4-{f(t)}", randint(3, 3_500),
            randint(3, 3_500), randint(500_000, 900_000))

    gen(f"4-04", 3_500, 3_500, 500_000)
    gen(f"4-05", 3_500, 3_500, 800_000)

    # * SUBTASK 5
    for t in range(1, 6+1):
        gen(f"5-{f(t)}", randint(3, 10_000),
            randint(3, 10_000), randint(500_000, 900_000))

    gen(f"5-07", 10_000, 10_000, 500_000)
    gen(f"5-08", 10_000, 10_000, 800_000)
    gen(f"5-09", 10_000, 10_000, 992_000)
