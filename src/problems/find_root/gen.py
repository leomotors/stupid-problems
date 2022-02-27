
# * General: O = 10, RVL = 10^9

# * 1. (1 Point) The answer of all tests are 69
# * 2. (5 Points) The polynomial is linear
# * 3. (9 Points) The polynomial is parabola
# * 4. (17 Points) All roots lie between -1000 and 1000
# * 5. (10 Points) O = ∞
# * 6. (13 Points) O ∈ {69 420, 177 013}
# * 7. (14 Points) O = 1000
# * 8. (31 Points) No Additional Constraints

# * Args: T (lim = 100), F, O, RCL (Root Count Limit), RVL (Root Value Limit)

def useGenerator(gen):
    gen(1, 314, 5, 1, 10, 10, 69)
    gen(2, 696, 100, 5, 10, 1, 10**9)
    gen(3, 420, 100, 9, 10, 2, 10**9)
    gen(4, 177, 100, 17, 10, 10, 1000)
    gen(5, 130, 100, 10, 2*10**9 + 2, 10, 10**9)
    gen(6, 456, 100, 13, 69420, 10, 10**9)
    gen(7, 789, 100, 14, 1000, 10, 10**9)
    gen(8, 120, 100, 31, 10, 10, 10**9)
