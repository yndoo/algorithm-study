import sys
input = sys.stdin.readline

R, C, N = map(int,input().split())
graph = [[0 for _ in range(C)] for _ in range(R)]
for i in range(R):
    s = input()
    for j in range(len(s)):
        if s[j]=='O': graph[i][j]=1

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

cnt=1
while cnt<N:
    #폭탄 없는곳 설치, 이미 있는 폭탄 +=1
    for i in range(R):
        for j in range(C):
            graph[i][j]+=1
    cnt+=1
    if cnt<N:
        #터지는 폭탄 터트리기
        for i in range(R):
            for j in range(C):
                if graph[i][j]==2:
                    #폭탄없애기
                    graph[i][j]=0
                    flag = True
                    for k in range(4):
                        nx = i+dx[k]
                        ny = j+dy[k]
                        if nx>=0 and nx<R and ny>=0 and ny<C:
                            if graph[nx][ny]==2: continue
                            graph[nx][ny]=0
        cnt+=1          
    else: break

for i in range(R):
    for j in range(C):
        if graph[i][j]==0:
            print('.', end='')
        else: print('O', end='')
    print('\n',end='')