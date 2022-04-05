n = int(input())
cnt = 0
for i in range(n):
    s = input()
    if "minos" in s:
        cnt+=1
if cnt<n/2: print("YES")
else: print("NO")