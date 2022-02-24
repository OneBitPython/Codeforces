one = len(input().split(".")[1])
two = len(input().split(".")[1])
three = len(input().split(".")[1])
four = len(input().split(".")[1])

l = [one, two, three, four]
a = ["A", "B", "C", "D"]
ans = []
for i in range(0, 4):
    pos = True
    for j in range(0, 4):
        if(i!=j):
            if l[i] * 2 > l[j]:
                pos = False
    if pos:
        ans.append(a[i])
    else:
        pos = True
        for j in range(0, 4):
            if(i!=j):
                if l[j] * 2 > l[i]:
                    pos = False
        if pos:
            ans.append(a[i])

if(len(ans) == 1):
    print(ans[0])
else:print("C")