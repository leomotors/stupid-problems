
# * 30 คะแนน : N <= 1000, M <= 2000, T <= 100
# * 70 คะแนน : N <= 100000, M <= 400000, T <= 200

# * ARG = N, M, W

from random import randint, seed


def useGenerator(gen):
    seed(69420)
    gen("s1", 5, 8, 10)

    for i in range(1, 6+1):
        gen(i, randint(690, 1000), randint(1400, 2000), randint(69, 100))

    for i in range(7, 20+1):
        gen(i, randint(80000, 100000), randint(
            340000, 400000), randint(112, 200))
