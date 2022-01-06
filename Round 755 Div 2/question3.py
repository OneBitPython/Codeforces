for q in range(int(input())):
    size = int(input())
    a = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())))
    ans = "YES"
    for one, two in zip(a, b):
        if one != two:
            if two-one >1:
                ans = "NO"
                break
    print(ans)