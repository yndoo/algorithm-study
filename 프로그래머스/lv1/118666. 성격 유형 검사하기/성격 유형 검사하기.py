def solution(survey, choices):
    answer = ["R","C","J","A"]
    scores=[0,0,0,0]
    print(scores)
    for i in range(len(survey)):
        if choices[i]==4:
            continue
        else:
            if survey[i][0]=="R":
                if choices[i]<4:
                    scores[0]+=(4-choices[i])
                elif choices[i]>4:
                    scores[0]-=(choices[i]-4)
            elif survey[i][0]=="T":
                if choices[i]<4:
                    scores[0]-=(4-choices[i])
                elif choices[i]>4:
                    scores[0]+=(choices[i]-4)
            if survey[i][0]=="C":
                if choices[i]<4:
                    scores[1]+=(4-choices[i])
                elif choices[i]>4:
                    scores[1]-=(choices[i]-4)
            elif survey[i][0]=="F":
                if choices[i]<4:
                    scores[1]-=(4-choices[i])
                elif choices[i]>4:
                    scores[1]+=(choices[i]-4)
            if survey[i][0]=="J":
                if choices[i]<4:
                    scores[2]+=(4-choices[i])
                elif choices[i]>4:
                    scores[2]-=(choices[i]-4)
            elif survey[i][0]=="M":
                if choices[i]<4:
                    scores[2]-=(4-choices[i])
                elif choices[i]>4:
                    scores[2]+=(choices[i]-4)
            if survey[i][0]=="A":
                if choices[i]<4:
                    scores[3]+=(4-choices[i])
                elif choices[i]>4:
                    scores[3]-=(choices[i]-4)
            elif survey[i][0]=="N":
                if choices[i]<4:
                    scores[3]-=(4-choices[i])
                elif choices[i]>4:
                    scores[3]+=(choices[i]-4)
                    
    for i,s in enumerate(scores):
        if s < 0:
            if i==0:
                answer[0]="T"
            elif i==1:
                answer[1]="F"
            elif i==2:
                answer[2]="M"
            elif i==3:
                answer[3]="N"           
    return ''.join(answer)