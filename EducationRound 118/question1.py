

for q in range(int(input())):
    x1, p1 = map(int,input().split())
    x2, p2 = map(int,input().split())

    if len(str(x1))+p1 > len(str(x2))+p2:
        print(">")
        continue
    elif len(str(x1))+p1 < len(str(x2))+p2:
        print("<")
    else:
        new1=str(x1)
        new2=str(x2)
        max_ = max(len(new1),len(new2))
        if len(new1)>len(new2):
            new2+=(len(new1)-len(new2))*"0"
        else:
            new1+=(len(new2)-len(new1))*"0"
        if int(new1)>int(new2):
            print(">")
        elif int(new2)>int(new1):
            print("<")
        else:
            print("=")
