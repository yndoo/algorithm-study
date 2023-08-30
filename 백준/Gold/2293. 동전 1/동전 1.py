import sys
myinput = sys.stdin.readline

N, K = map(int, myinput().split())
kinds = []
ways = [0]*(K+1)
for _ in range(N):
    x = int(myinput())
    if x<=K:
        kinds.append(x)
kinds.sort()
ways[0] = 1
for coin in kinds:
    for i in range(K+1):
        if i+coin<=K:
            ways[i+coin] = ways[i+coin] + ways[i]
print(ways[K])