import math
for q in range(int(input())):
    n = int(input());
    n*=2;
    print((math.factorial(n)/2)%(1e9+7))