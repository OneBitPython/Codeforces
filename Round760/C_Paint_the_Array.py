for q in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    first = []
    second = []
    for i in range(len(arr)):
        if i%2==0:
            first.append(arr[i])
        else:
            second.append(arr[i])
    first.sort()
    second.sort()
    val = first[0]
    b=False
    for i in first:
        if i%val!=0:
            b=False
            break
    else:
        for i in second:
            if i%val==0:
                b=False
                break
        else:
            b=True
            print(val)
    if b==False:
        val2 = second[0]
        for i in second:
            if i%val2!=0:
                b=False
                break
        else:
            for i in first:
                if i%val2==0:
                    b=False
                    break
            else:
                b=True
                print(val2)
        if b==False:
            print(0)
            