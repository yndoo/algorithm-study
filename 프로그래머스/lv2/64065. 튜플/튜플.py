def solution(s):
    answer = []
    exp = []
    #집합 리스트 만들기
    for ss in s.split('{'):
        if ss:
            tmp = []
            mystr=""
            for num in ss:
                if num == '}': 
                    tmp.append(int(mystr))                   
                    break
                if num == ',': 
                    tmp.append(int(mystr))
                    mystr=""
                    continue
                mystr+=num
            exp.append(tmp)
            
    exp.sort(key=len) #길이 기준 정렬
    
    for x in exp: #길이 적은 집합부터 하나씩 보기
        for xx in x:
            if xx not in answer: #answer에 없는 숫자가 추가돼있으면 해당 순서 튜플임
                answer.append(xx)
    return answer