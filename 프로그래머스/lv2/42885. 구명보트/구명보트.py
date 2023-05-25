def solution(people, limit):
    answer = 0
    mini,maxi=0,0 #인덱스
    people.sort()
    for i, p in enumerate(people):
        if p>limit-40: #확정 1인 보트 인원 제외
            answer+=len(people)-i
            people=people[:i]
            break

    maxi = len(people)-1
    mini=0
    while mini<=maxi:
        if mini==maxi:
            answer+=1
            break
        if people[mini]+people[maxi]<=limit:
            answer+=1
            mini+=1
            maxi-=1
        else:
            maxi-=1
            answer+=1
    return answer