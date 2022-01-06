for i in range(int(input())):

    n = int(input())
    arr = list(map(int, input().split()))
    balls = input()

    validatation = list(range(1, n+1))
    red = []
    blue = []
    output = []

    for i in range(len(arr)):
        if balls[i] == "R":
            red.append(arr[i])
        else:
            blue.append(arr[i])

    red.sort()
    blue.sort()
    ans = "YES"
    for i in range(1, len(blue)+1):
        req_val = i
        if blue[i-1] < req_val:
            ans = "NO"
            break
        else:
            output.append(i)
    for i in range(len(blue), len(red)+len(blue)):
        req_val = i+1
        if red[i-len(blue)] > req_val:
            ans = "NO"
            break
        else:
            output.append(i+1)
    if output != validatation:
        ans = "NO"
    print(ans)