import sys
myinput = sys.stdin.readline

N, D = map(int,myinput().split())
graph = [list(map(int, myinput().split())) for _ in range(N)]
dp = [i for i in range(D+1)] #0~D

for d in range(D+1):
    dp[d] = min(dp[d], dp[d-1]+1)
    for s, e, k in graph:
        if d==s and e<=D and dp[d]+k<dp[e]:
            dp[e] = dp[d]+k
print(dp[D])