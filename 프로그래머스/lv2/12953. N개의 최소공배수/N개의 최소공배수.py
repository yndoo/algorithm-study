def solution(arr):
    limit=1
    for i in arr:
        limit = limit*i
    for num in range(max(arr),limit+1):
        for i in arr:
            if num%i!=0: break
        else:
            return num