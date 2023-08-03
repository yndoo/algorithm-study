import sys
myinput = sys.stdin.readline
sys.setrecursionlimit(10**9)

N = int(myinput())
graph = []
for _ in range(N):
    graph.append(list(map(int, myinput().split())))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y, num):
    if visited[x][y] == 0:
        visited[x][y] = 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx<0 or nx>=N or ny<0 or ny>=N:
                continue
            if visited[nx][ny]==0 and graph[nx][ny]>num:
                dfs(nx,ny,num)
        return True
    return False

num=0 # 잠기는 높이
res = []
for num in range(0,101):
    visited = [[0] * N for _ in range(N)]
    cnt=0 # 안전 영역 개수
    for i in range(N):
        for j in range(N):
            if graph[i][j]>num and dfs(i,j, num):
                cnt+=1
    res.append(cnt)
print(max(res))
