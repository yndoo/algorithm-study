import sys
myinput = sys.stdin.readline

graph = dict()
N = int(myinput())

for i in range(1,N+1):
    graph[i] = int(myinput())
res=[]
def iscycle(cur, visited):
    if visited[graph[cur]]==1:
        res.append(graph[cur])
    else:
        visited[cur]=1
        iscycle(graph[cur],visited)

for i in range(1,N+1):
    iscycle(i,[0]*(N+1))
res = set(res)
print(len(res))
print('\n'.join(map(str,sorted(res))))