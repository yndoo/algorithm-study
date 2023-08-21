import sys
from collections import deque
myinput = sys.stdin.readline

N, K = map(int, myinput().split())
visited = [0] * (10**5 + 1)

def bfs(N):
    q = deque()
    q.append((N, 0))
    cnt=0
    while q:
        x, cnt = q.popleft()
        visited[x] = 1
        if x==K:
            print(cnt)
            break
        if 0<=x*2<=10**5 and visited[x*2]==0:
            q.appendleft((x*2,cnt))
        if 0<=x-1<=10**5 and visited[x-1]==0:
            q.append((x-1, cnt+1))
        if 0<=x+1<=10**5 and visited[x+1]==0:
            q.append((x+1,cnt+1))

bfs(N)