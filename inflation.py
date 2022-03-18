def pos(x, a, k):
    sum_ = a[0]+x
    ok = 1
    for i in range(1, n):
        curr = a[i]/sum_
        if(curr > (k/100)):ok = 0
        sum_ += a[i]
    return ok

for q in range(int(input())):
    n, k = map(int, input().split());
    a = list(map(int,input().split()))
    l = 0
    r = 1e18
    while(l+1 < r):
        mid = (l+r)//2
        if(pos(mid, a, k)):
            r = mid
        else:
            l = mid
            
    l = int(l)
    r = int(r)
    if pos(l, a, k):print(l)
    else: print(r)