for q in range(int(input())):
    n = int(input())
    s = input()
    ans = s[0]
    current = s[0]
    reverse = current
    if n>1:
        # if s[0]==s[1]:
        #     print(s[0]+s[1])
        # else:
            for i in range(1,len(s)):
                if s[i] <= current:
                    ans+=s[i]
                else:
                    break
                current =s[i]
            print(ans+ans[::-1])
    else:
        print(s[0]+s[0])