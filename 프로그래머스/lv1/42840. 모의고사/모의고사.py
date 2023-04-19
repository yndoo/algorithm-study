def solution(answers):
    answer=[]
    student1 = [1,2,3,4,5]
    student2 = [2,1,2,3,2,4,2,5]
    student3 = [3,3,1,1,2,2,4,4,5,5]
    cnt=[0,0,0]
    for i in range(len(answers)):
        if answers[i] == student1[i%len(student1)]:
            cnt[0]+=1
        if answers[i] == student2[i%len(student2)]:
            cnt[1]+=1
        if answers[i] == student3[i%len(student3)]:
            cnt[2]+=1
    
    for i in range(3):
        if cnt[i]==max(cnt):
            answer.append(i+1)
    return answer