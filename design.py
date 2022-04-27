n = int(input())
a = []
for i in range(n):
    s, t = map(str,input().split());
    a.append([s,t])
p = list(map(int,input().split()));
prev = min(a[p[0]-1][0], a[p[0]-1][1])
ok = 1;
for i in range(1,n):
    s = a[p[i]-1][0]
    t = a[p[i]-1][1]
    if t < s:s,t = t,s

    if s > prev:
        prev = s
    elif t > prev:
        prev = t
    else:
        ok = 0
        break
if ok:print("YES")
else: print("NO");