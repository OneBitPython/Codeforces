
for q in range(int(input())):
    u, v = map(int, input().split())
    print(-(u**2), v**2)
# for q in range(int(input())):
#     u, v = map(int, input().split())
#     lcm = u*v
#     x1, y1 = lcm/u, lcm/v
#     sum_ = u+v
#     lhs1 = (sum_ * x1)
#     lhs2 = (sum_ * y1)
#     rhs1, rhs2 = lcm, lcm

#     lhs = lhs1 - rhs1
#     rhs = rhs2 - lhs2

#     x, y = rhs, lhs
#     ans1 = (x/u)+(y/v)
#     ans2 = (x+y)/(u+v)
#     if ans1 == ans2:

#         print(int(x), int(y))
#     else:
#         print(int(x*2), int(y*2))
