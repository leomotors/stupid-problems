
from random import randint, seed


def useGenerator(gen):
    seed(69420)
    for i in range(1, 6):
        gen(f"1-{i}", randint(1, 1_000_000), 0, 2546)

    for i in range(1, 6):
        gen(f"2-{i}", randint(1, 1_000_000), -1_000_000_000, 1_000_000_000)

    for i in range(1, 16):
        gen(f"3-{i}", 7892, -1_000_000_000_000_000_000,
            1_000_000_000_000_000_000)

    for i in range(1, 2+1):
        gen(f"4-{i}", randint(1, 1_000_000), -
            1_000_000_000_000_000_000, 1_000_000_000_000_000_000)

    for i in range(3, 4+1):
        gen(f"4-{i}", randint(900_000, 1_000_000), -
            1_000_000_000_000_000_000, 1_000_000_000_000_000_000)
