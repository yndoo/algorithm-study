from collections import deque
n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input())))

visited = [[0 for _ in range(m)] for _ in range(n)]

dx=[-1,0,1,0]
dy=[0,1,0,-1]


def bfs(x,y):
  queue = deque()
  queue.append((x,y))
  
  while queue:
    x,y=queue.popleft()
    if(visited[x][y]==0):
      visited[x][y]=1
      for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if(nx>=n or ny>=m or nx<0 or ny<0):
          continue
        if(visited[nx][ny]==0 and graph[nx][ny]==1):
          queue.append((nx,ny))
          graph[nx][ny]=graph[x][y]+1
          


bfs(0,0)
print(graph[n-1][m-1])