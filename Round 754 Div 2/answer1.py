for i in range(int(input())):
    a, b, c, = map(int, input().split())
    if (a+b+c) % 3 == 0:
        print(0)
    else:
        print(1)