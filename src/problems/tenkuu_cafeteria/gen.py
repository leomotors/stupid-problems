
# * C <= 100000, O <= 100000
# * 10 คะแนน : C <= 10, O <= 10
# * 20 คะแนน : C <= 100, O <= 10
# * 20 คะแนน : O <= 100
# * 20 คะแนน : O <= 5000
# * 30 คะแนน : ไม่มีเงื่อนไขเพิ่มเติม


def useGenerator(gen):
    gen(1, "Cocoa", 10, 7)
    gen(2, "Chino", 80, 5)
    gen(3, "Rize", 100, 10)
    gen(4, "Chiya", 10000, 69)
    gen(5, "Sharo", 100000, 100)

    gen(6, "Daydream Cafe", 100000, 2500)
    gen(7, "No Poi!", 500, 5000)

    gen(8, "Tenkuu Cafeteria", 50000, 50000)
    gen(9, "Sekai ga Cafe ni Natchatta", 70000, 70000)
    gen(10, "Nikkori Cafe no Mahou Tsukai", 100000, 100000)
