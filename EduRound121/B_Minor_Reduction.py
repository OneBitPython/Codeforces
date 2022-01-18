for q in range(int(input())):
    s = input()
    has = False
    for i in range(len(s)-1,0,-1):
        v = int(s[i])+int(s[i-1])
        if len(str(v))==2:
            has = True
            ans = s[:i-1]+str(v)
            if(i+1 <len(s)):
                ans+=s[i+1:]
            break;
        
    if has:
        print(ans)
    else:
        v = str(int(s[0])+int(s[1]))+s[2:]
        print(v)
