def solution(progresses, speeds):
    answer = []
    days = []
    for i,prg in enumerate(progresses):
        if (100-prg)%speeds[i]==0:
            days.append((100-prg)//speeds[i])
        else: days.append((100-prg)//speeds[i]+1)

    cnt = 0
    maxi = days[0]
    for d in days:
        if d > maxi:
            answer.append(cnt)
            cnt = 1
            maxi = d
        else:
            cnt+=1
    answer.append(cnt)
    return answer