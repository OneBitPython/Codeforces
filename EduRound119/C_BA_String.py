for q in range(int(input())):
    n, k, x = map(int,input().split())
    s = input()
    s = [i for i in s]
    remaining = x-1
    for j,i in enumerate(s):
        if i=="*":
            remaining-=1
            s[j] = "b"
    idx = len(s)-1
    k-=1
    while remaining>0:
        can_add = min(remaining, k)
        s.insert(idx, "b"*can_add)
        remaining-=k
        idx-=1
    print(s)