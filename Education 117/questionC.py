
from math import *
for q in range(int(input())):
    k,x = map(int, input().split())
    disc = 1+(8*x)
    ans = ceil((-1+sqrt(disc))/2.0)
    emj = (ans*(ans+1))//2.0
    mxh = (k*(k+1))//2
    x-=min(mxh, emj)
    ans=min(ans,k)
    if x>0:
        kh = (k * (k-1))//2
        if kh<=x:
            ans = 2*k-1
            print(ans)
        else:
            x=kh-x
            disc = 1 + (8*x)
            a = floor((-1+sqrt(disc)) // 2.0)+1-k
            print(ans-a)
    else:
        print(ans)


