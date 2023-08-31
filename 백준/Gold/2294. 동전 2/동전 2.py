import sys
myinput = sys.stdin.readline

N, K = map(int, myinput().split())
coins = []
for _ in range(N):
    coins.append(int(myinput()))

dp = [10001]*(K+1)
answer = 0
dp[0]=0
for coin in coins:
    for i in range(K+1):
        if i+coin<=K:
            dp[i+coin] = min(dp[i+coin], dp[i]+1)

if dp[K]==10001:
    print(-1)
else:
    print(dp[K])