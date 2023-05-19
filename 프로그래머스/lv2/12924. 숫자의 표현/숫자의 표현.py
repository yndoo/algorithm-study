def solution(n):
    answer = 1  #자기 자신도 포함이기 때문에 1로 시작
    for i in range(1,n):
        sum=0
        for j in range(i,n):
            if sum+j<=n: sum+=j
            else: break
            if sum==n:
                answer+=1
                break
    return answer