import math

for q in range(int(input())):
    arr = list(map(int, input().split()))
    output = []
    diff = arr[1]-arr[0]
    for i in range(len(arr)-1):
        if arr[i+1]-arr[i] != diff:
            ans = 0
            break
    else:
        ans = 1
    
    if ans:
        print(abs((arr[0]+arr[2]) - 2*arr[1]))
    else:
        mean = (arr[0]+arr[2]) //2
        a,b,c = arr[0], arr[1], arr[2]
        req = mean
        output.append(abs((a+c)-2*b))

        if a>c:
            req = abs(req-b)//2
            if b<req:

                d = (req - b)
                a -= d
                output.append(abs((a+c)-2*req))
                output.append(abs((a+c-1)-2*(req+1)))
            else:
                d = b - req
                a += d
                output.append(abs((a+c)-2*req))
                output.append(abs((a+c-1)-2*(req+1)))
        else:
            req = abs(req-b) // 2
            if b < req:
                d = req - b
                c -= d
                output.append(abs((a+c)-2*req))
                output.append(abs((a+c+1)-2*(req-1)))
            else:
                d = b - req
                c += d
                output.append(abs((a+c)-2*req))
                output.append(abs((a+c+1)-2*(req-1)))
        print(min(output))
