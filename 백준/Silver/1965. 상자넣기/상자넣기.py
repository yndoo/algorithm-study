import sys
myinput = sys.stdin.readline
N = int(myinput())
box = list(map(int, myinput().split()))
dp = [1] * N

for i in range(N):
    for j in range(i+1,N):
        if box[i]<box[j]:
            dp[j] = max(dp[j], dp[i]+1)
print(max(dp))