import math
for q in range(int(input())):
    n, h = map(int,input().split())
    seconds = list(map(int,input().split()))
    seconds.append(2**65)

    damage_dealt = 0
    k = 0
    differences =[]
    for i in range(1, n):
        difference = seconds[i]-seconds[i-1]
        differences.append(difference)
        k=difference
        if damage_dealt+difference < h:
            damage_dealt+=difference
    
    if damage_dealt < h:
        remaining = h - damage_dealt
        k =math.ceil(remaining/(n-i+1))
    print(k)
    # nk = math.ceil(h/n)
    # if nk <= min(differences):
    #     print(nk)
    # else:
    #     print(k)
