dp = []
for i in range(200001):
    
for q in range(int(input())):
    l,r = map(int,input().split())
    binaries = []
    for i in range(l,r+1):
        binary = bin(i)[2:]
        binaries.append(binary[::-1])
    final = 0
    for idx in range(len(binaries[0])):
        count = 0
        for binary in binaries:
            bit = binary[idx]
            if bit == "1":
                count+=1
        final = max(count,final)
    print(r-l+1-final)
    # final = 0
    # binaries = []
    # min_len = float("inf")
    # for i in range(l, r+1):
    #     binaries.append(bin(i)[2:])
    #     min_len = min(min_len, len(binaries[-1]))

    # for idx in range(-1,-min_len-1,-1):
    #     count = 0
    #     for value in binaries:
    #         bit = value[idx]
    #         if bit == "1":
    #             count+=1
    #     final = max(final, count) 
    # print(r-l+1 -final)
#     print(final)
# dp = [[0]*20]*200001
# for i in range(200001):
#     check, idx = i,0
#     while check:
#         dp[i][idx]+=(check%2)
#         idx+=1
#         check >>=1
#     for j in range(20):
#         if (i):
#             dp[i][j] += dp[i-1][j]
# for q in range(int(input())):
#     l,r = map(int,input().split())