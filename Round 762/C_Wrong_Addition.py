for q in range(int(input())):
    a,c = input().split()
    a = [i for i in a]
    c = [i for i in c]

    ans = ""
    while a and c:
        one = a.pop(-1)
        two = c.pop(-1)
        one=int(one)
        two = int(two)
        if one < two:
            ans+=str(two-one)
        elif one == two:
            ans+='0'
        else:
            if c and c[-1]=="1":
                new_two = c.pop(-1)
                if new_two!="1":
                    break
                new_val = new_two+str(two)
                ans+=str(int(new_val)-one)
            else:
                ans=-1
                break
    if ans!=-1:
        while c:
            u = c.pop(-1)
            
            ans+=str(u)
    if a or  ans==-1:
        print(-1)
    else:
        print(ans[::-1].lstrip("0"))