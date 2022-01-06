for q in range(int(input())):
    n = input()
    s = [i for i in input()]
    t = [i for i in input()]
    c = "".join(s)
    d = "".join(t)
    if c == d:
        print(-1)
    elif c<d:
        print(0)
    else:
        ans = 0
        for i in range(len(s)):
            if "".join(s) < "".join(t):
                break
        
            if s[i] <= t[i]:
                if i<len(s)-1:
                    ans+=1
                    s[i],s[i+1] = s[i+1],s[i]
        print(ans)
