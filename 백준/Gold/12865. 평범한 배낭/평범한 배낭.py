import sys
myinput = sys.stdin.readline

N, K = map(int,myinput().split())
W = [0] * (N+1)
V = [0] * (N+1)
dp = [[0] * (K+1) for _ in range(N+1)]
for i in range(1,N+1):
    W[i], V[i] = map(int,myinput().split())

for i in range(1,N+1):
    for j in range(1,K+1):
        if j-W[i]>=0:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+V[i])
        else:
            dp[i][j] = dp[i-1][j]
print(dp[N][K])