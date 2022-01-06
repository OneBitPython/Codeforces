for  i in range(int(input())):

    n = int(input())
    s = input()
    lst = []


    for i, j in enumerate(s):
        if j == "a":
            lst.append(i)
    output = []
    for i in range(len(lst)-1):
        for j in range(i, len(lst)-1):
            tmp = s[lst[i]:lst[j+1]+1]
            if len(tmp)<=7:
                if tmp.count("a")>tmp.count("c") and tmp.count("a") > tmp.count("b"):
                    output.append(tmp)
    if output:
        print(len(min(output, key=lambda x : len(x))))
    else:
        print("-1")