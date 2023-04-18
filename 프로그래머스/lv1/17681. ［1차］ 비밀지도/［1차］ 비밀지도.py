def solution(n, arr1, arr2):
    answer=[]
    for i in range(n):
        all=""
        x = arr1[i]|arr2[i]
        cnt=0
        while cnt<n:
            cnt+=1
            if x%2==1: all="#"+all
            else: all=" "+all
            x=x//2
        answer.append(all)

    return answer