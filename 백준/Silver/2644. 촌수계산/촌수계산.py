from collections import deque

n = int(input())
s,e=map(int,input().split())
m = int(input())

graph = [[] for _ in range(n+1)] 
visited=[0 for _ in range(n+1)]

for _ in range(m):
  a,b=map(int,input().split())
  graph[a].append(b)
  graph[b].append(a)

def bfs(s,e):
  if(s==e):
    return 0
  queue = deque()
  queue.append(s)
  visited[s]=1
  res=0
  while queue:
    x = queue.popleft()
    cnt=0
    for i in graph[x]:
      if(visited[i]==0):
        queue.append(i)
        visited[i]=visited[x]+1
        if(cnt==0):
          res+=1
        cnt+=1
      if(i==e):
        return visited[i]-1


  return -1
  

print(bfs(s,e))