import sys
myinput = sys.stdin.readline

N = int(myinput())
graph = []
cnt = 0 # 영역 개수 카운트
nums = 0 # 각 영역 장애물 개수
result = []
for _ in range(N):
    graph.append(list(map(int, myinput().rstrip())))
visited = [[0]*N for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y):
    global nums
    if visited[x][y] == 0:
        visited[x][y] = 1
        nums+=1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx<0 or nx>=N or ny<0 or ny>=N:
                continue
            if graph[nx][ny]==1 and visited[nx][ny]==0:
                dfs(nx,ny)
        return True
    return False

for i in range(N):
    for j in range(N):
        if graph[i][j]==1:
            if dfs(i,j):
                cnt+=1
                result.append(nums)
                nums=0


print(cnt)
result.sort()
print('\n'.join(map(str,result)))
