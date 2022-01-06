from itertools import combinations
from collections import defaultdict
for q in range(int(input())):
    N = int(input())
    arr = list(map(int,input().split()))
    freq = defaultdict(lambda : 0)
        
    for i in arr:
        freq[i]+=1

    pairs = 0
    p = []
    for i in range(N-1):
        if pairs >= N//2:
            break

        for j in range(i+1, N):
            x = arr[i]
            y = arr[j]
            if x!=y and x in arr and y in arr:
                if freq[x%y]==0:
                    if [x,y] not in p:
                        print(x,y)
                        pairs+=1
                        p.append([x,y])
                if pairs >=N//2:
                    break
                if freq[y%x]==0:
                    if [y,x] not in p:
                        print(y,x)
                        pairs += 1
                        p.append([y,x])
