import sys
myinput = sys.stdin.readline
N, K = map(int, myinput().split())

dp = [[0]*(N+1) for _ in range(K+1)]
for i in range(N+1):
    dp[1][i] = 1

for k in range(1,K+1):
    for n in range(N+1):
        for l in range(n+1):
            dp[k][n] += dp[k-1][n-l]
print(dp[K][N]%(10**9))