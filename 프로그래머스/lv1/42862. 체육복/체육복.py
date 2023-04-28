def solution(n, lost, reserve):
    #lost.sort()
    #reserve.sort()
    maxi = n-len(lost)
    real_lst = [1] * n
    
    
    for r in reserve:    #여벌 개수 채우기
        real_lst[r-1]+=1
    for l in lost:    #도난 당한 개수 지우기
        if l in reserve:
            maxi+=1
        real_lst[l-1]-=1

    #i-1부터 검색
    lst=real_lst
    cnt=maxi
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
    '''
    #i+1부터 검색
    for i in range(n):
        if real_lst[i]==0:
            if i+1<n and real_lst[i+1]==2:
                real_lst[i+1]-=1
                real_lst[i]+=1
                maxi+=1
            elif i-1>=0 and real_lst[i-1]==2:
                real_lst[i-1]-=1
                real_lst[i]+=1
                maxi+=1
                '''
    
    #return max(cnt,maxi)
    return cnt