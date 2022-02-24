for i in range(int(input())):
    n = int(input())
    ans = 0
    min_ = 100000
    for i in range(0, 1000, 7):
        if(len(str(i)) != len(str(n))):continue
        cnt = 0
        for w,j in zip(str(i), str(n)):
            if w!=j:
                cnt+=1
        if cnt < min_:
            ans = i
            min_ = cnt
    print(ans)