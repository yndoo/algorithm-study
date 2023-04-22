def solution(N, stages):
    answer = []
    stage = [0] * (N+1)
    fail = [[0, 0] for _ in range(N)]
    entire=0
    
    for s in stages:
        stage[s-1]+=1
        entire+=1

    for i in range(N):
        fail[i][0]=i+1
        if stage[i]==0: continue
        fail[i][1]=stage[i]/entire
        entire-=stage[i]

    
    fail.sort(key=lambda x: (-x[1],x[0]))
    for ans,rate in fail:
        answer.append(ans)
        
    return answer