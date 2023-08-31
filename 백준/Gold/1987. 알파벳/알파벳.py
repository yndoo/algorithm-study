import sys
myinput = sys.stdin.readline

R, C = map(int, myinput().split())
graph = []
for _ in range(R):
    graph.append(list(myinput()))

dx = [0,0,1,-1]
dy = [1,-1,0,0]
answer = 0

def dfs(x, y, alpha, cnt):
    global answer
    answer = max(answer, cnt)
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx<0 or ny<0 or nx>=R or ny>=C:
            continue
        if graph[nx][ny] in alpha: continue

        alpha.add(graph[nx][ny])
        dfs(nx, ny, alpha, cnt+1)
        alpha.remove(graph[nx][ny])

    return True



dfs(0,0,set([graph[0][0]]), 1)
print(answer)