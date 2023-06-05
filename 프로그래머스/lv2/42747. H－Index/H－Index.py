def solution(citations):
    citations.sort()
    i=0
    h=0
    while (i<len(citations)):
        if citations[i]>=h and len(citations)-i >= h:
            h+=1
        else:
            i+=1
    return h-1