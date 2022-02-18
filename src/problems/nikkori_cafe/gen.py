
# * N <= 1e9, A <= N, P <= 6000000
# * 20 คะแนน : N <= 100
# * 10 คะแนน : A = 1
# * 10 คะแนน : P = 2
# * 20 คะแนน : P <= 50000
# * 40 คะแนน : ไม่มีเงื่อนไขเพิ่มเติม


def useGenerator(gen):
    gen("s1", "Sample 1", 8, 3, 4)
    gen("s2", "Sample 2", 8, 6, 4)

    gen(1, "Cocoa", 40, 4, 5)
    gen(2, "Chino", 100, 17, 2000)

    gen(3, "Rize", 200000, 1, 50000)

    gen(4, "Chiya", 10**7, 10**3, 2)

    gen(5, "Sharo", 10**7, 112, 49999)
    gen(6, "Daydream Cafe", 10**8, 14000, 50000)

    gen(7, "No Poi!", 10**8, 10**4, 2*10**6)
    gen(8, "Tenkuu Cafeteria", 10**8, 10**4 + 20, 2*10**6)
    gen(9, "Sekai ga Cafe ni Natchatta", 10**8, 10**3, 2*10**6)
    gen(10, "Nikkori Cafe no Mahou Tsukai", 10**9, 3*10**6, 6*10**6)
