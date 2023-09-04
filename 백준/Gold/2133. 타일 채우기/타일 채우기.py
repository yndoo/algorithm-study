import sys
myinput = sys.stdin.readline
N = int(myinput())

lst = [0] * (N+1)

def dp(x):
    if x == 0:
        return 1
    if x == 1:
        return 0
    if x == 2:
        return 3
    if lst[x]!=0:
        return lst[x]
    answer = 3 * dp(x-2)
    for i in range(3, x+1):
        if i%2==0:
            answer += 2 * dp(x-i)
    lst[x] = answer
    return lst[x]

print(dp(N))