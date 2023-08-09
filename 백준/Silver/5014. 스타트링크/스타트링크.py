import sys
from collections import deque
myinput = sys.stdin.readline

F, S, G, U, D= map(int, myinput().split())
visited = [0] * (F)
count = [0] * (F)

def bfs(i):
    q = deque()
    q.append(i)
    visited[i-1] = 1
    while q:
        x = q.popleft()
        if x == G:
            return count[x-1]
        if x+U<=F and visited[x+U-1]==0:
            q.append(x+U)
            visited[x+U-1] = 1
            count[x+U-1] = count[x-1] + 1
        if x-D>=1 and visited[x-D-1]==0:
            q.append(x-D)
            visited[x - D - 1] = 1
            count[x-D-1] = count[x-1]+1
    return "use the stairs"

print(bfs(S))