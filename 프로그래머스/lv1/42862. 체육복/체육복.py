def solution(n, lost, reserve):
    cnt = n-len(lost)
    lst = [1] * n
    
    
    for r in reserve:    #여벌 개수 채우기
        lst[r-1]+=1
    for l in lost:    #도난 당한 개수 지우기
        if l in reserve:
            cnt+=1
        lst[l-1]-=1

    for i in range(n):
        if lst[i]==0:
            if i-1>=0 and lst[i-1]==2:
                lst[i-1]-=1
                lst[i]+=1
                cnt+=1
            elif i+1<n and lst[i+1]==2:
                lst[i+1]-=1
                lst[i]+=1
                cnt+=1

    return cnt
