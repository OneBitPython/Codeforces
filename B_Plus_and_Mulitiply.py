for i in range(int(input())):
    n,a,b = map(int,input().split())
    ok = 0;
    if b== 1:ok = 1
    if ((n-1)%b == 0):ok = 1
    if a == 1:
        if (n-1)%b == 0:
            print("YES")
        else:
            print("NO")
    else:
        if ok:
            print("Yes")
        else:
            val = 1;
            while val <= n:
                if (n%b) == (val%b):
                    ok = 1
                    break
                val*=a
            print("Yes") if ok else print("No")