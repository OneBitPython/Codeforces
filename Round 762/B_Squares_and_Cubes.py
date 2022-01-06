import math  # for sqrt()

# Function to count the number
# of perfect squares and cubes


def countSC(N):
    res = (int(math.sqrt(N)) +
           int(N ** (1 / 3)) -
           int(math.sqrt(N ** (1 / 3))))

    return res


# Driver code




# Driver code
for q in range(int(input())):
    n = int(input())

    print(countSC(n+1))
