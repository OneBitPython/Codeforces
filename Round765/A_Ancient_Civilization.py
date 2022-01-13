for q in range(int(input())):
    n, l = map(int,input().split())
    arr= list(map(int,input().split()))
    binaries = []
    for i in arr:
        bina=  bin(i)[2:]
        required = l-len(bina)
        bina = "0"*required + bina
        binaries.append(bina[::-1])
    ans = ""
    for i in range(0,l):
        count = 0
        for value in binaries:
            if value[i] == '1':
                count+=1
        if(count >(n-count)):
            ans+="1"
        else:
            ans+="0"
    print(int(ans[::-1],2))