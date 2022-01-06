for q in range(int(input())):
    n, m = map(int, input().split())
    if n == 1 or m == 1:
        print(max(n, m)//2)
    else:
        max_ = max(n, m)
        if max_ % 2 == 0:
            max_ //= 2
        else:
            max_ -= 1
            max_ //= 2
        max_ += min(n, m)
        print(max_)