import sys
from collections import deque
myinput = sys.stdin.readline

N, M = map(int, myinput().split())
graph = [list(map(int,myinput().split())) for _ in range(N)]
visited = [[0]*M for _ in range(N)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(i,j):
    q = deque()
    q.append((i,j))
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx<0 or ny<0 or nx>=N or ny>=M or graph[nx][ny]==0 or visited[nx][ny]!=0:
                continue
            q.append((nx,ny))
            visited[nx][ny] = visited[x][y]+1
for i in range(N):
    for j in range(M):
        if graph[i][j]==2:
            bfs(i,j)
            visited[i][j] = 0
            break

for i in range(N):
    for j in range(M):
        if visited[i][j]==0 and graph[i][j]==1:
            visited[i][j] = -1
    print(' '.join(map(str, visited[i])))