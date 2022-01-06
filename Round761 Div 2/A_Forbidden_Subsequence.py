

for q in range(int(input())):
    s = input()
    t = input()
    s = [i for i in s]
    s.sort(key=lambda x :ord(x))
    
    ans = ""

    b=True
    for val in t:
        if val not in s:
            b=False
    
    if b:
        if t=="abc":
            count_b = s.count("b")
            count_c = s.count("c")
            last_index_c = len(s) 
            for j in range(len(s)-1, -1,-1):
                if s[j] == 'c':
                    last_index_c = j
                    break

            for i in s:
                if i=="b":
                    break
                else:
                    ans+=i
            for i in range(count_c):
                ans+="c"
            for i in range(count_b):
                ans+="b"
            for i in range(last_index_c+1, len(s)):
                ans+=s[i]
            print("".join(ans))
        else:
            print("".join(s))
    else:
        print("".join(s))
        