def solution(dartResult):
    answer=0
    scores=[]
    i=0
    print(len(dartResult))
    while i+1 < len(dartResult):
        if dartResult[i+1]=="0":    #숫자 두 자릿수인지 확인
            scores.append(10)
            i+=1
        else:
            scores.append(int(dartResult[i]))
        
        if dartResult[i+1]=="D":    #보너스 확인
            scores[-1]=scores[-1]**2
        elif dartResult[i+1]=="T":
            scores[-1]=scores[-1]**3

        if i+2>=len(dartResult): break    #끝났는지 확인
        if dartResult[i+2].isdigit():    #옵션이 없는지 확인
            i+=2
            continue
        elif dartResult[i+2]=="*":    #옵션이 '*'일 때
            if len(scores)>1: scores[-1],scores[-2]=scores[-1]*2,scores[-2]*2
            else: scores[-1]=scores[-1]*2
            i+=3
        else:    #옵션이 '#'일 때
            scores[-1]*=(-1)
            i+=3

    return sum(scores)