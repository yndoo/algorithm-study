def solution(k, tangerine):
    cnt = {}
    
    for i in set(tangerine):
        cnt[i]=0
    for t in tangerine:
        cnt[t]+=1

    count = list(cnt.values())
    count.sort(reverse=True)
    
    for i,j in enumerate(count):
        k-=j
        if k<=0: return i+1
