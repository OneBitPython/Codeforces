for i in range(int(input())):
    s = input()
    sum1 = int(s[0])+int(s[1])+int(s[2])
    sum2 = int(s[-1])+int(s[-2])+int(s[-3])
    if(sum1 == sum2):print("YES")
    else: print("NO")