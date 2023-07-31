import heapq

def solution(scoville, K):
    answer = 0
    lst=[]
    for sc in scoville:
        heapq.heappush(lst,sc)
    while lst[0]<K and len(lst)>1:
        s1 = heapq.heappop(lst)
        s2 = heapq.heappop(lst)
        heapq.heappush(lst,s1+s2*2)
        answer+=1
    
    if lst and heapq.heappop(lst)<K:
        return -1
    else:
        return answer