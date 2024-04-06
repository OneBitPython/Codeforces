n = int(input())
for i in range(n):
    s = input()
    hh = int(s[:2])
    b = "AM"
    if hh==12:b = "PM"
    if hh > 12:
        hh %=12
        b = "PM"
    if hh==0:
        hh = 12
    if len(str(hh))==1:print("0",end="")
    print(str(hh)+":"+s[3:]+" " +b)