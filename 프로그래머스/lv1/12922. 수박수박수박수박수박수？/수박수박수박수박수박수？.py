def solution(n):
    answer = ''
    for i in range((n+1)//2):
        answer += '수박'
    if n%2==1:
        return answer[:len(answer)-1]
    return answer