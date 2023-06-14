def solution(str1, str2):
    answer = 0
    s1dict = {}
    union = 0 #합집합 크기
    intersection = 0 #교집합 크기
    for i, s1 in enumerate(str1):
        if i == len(str1)-1: break 
        if s1.isalpha() and str1[i+1].isalpha(): #둘다 알파벳이면 다중집합의 원소
            tmp = s1.lower()+str1[i+1].lower()
            union+=1
            if s1dict.get(tmp)==None: #딕셔너리에 없으면 새로 추가
                s1dict[tmp]=1
            else: s1dict[tmp]+=1
    print(s1dict)
    
    
    for i, s2 in enumerate(str2):
        if i == len(str2)-1: break 
        if s2.isalpha() and str2[i+1].isalpha():
            tmp = s2.lower()+str2[i+1].lower()
            if s1dict.get(tmp)==None: #s1dict에 없었으면 합집합 크기 추가
                union += 1
            elif s1dict[tmp]>=1: 
                s1dict[tmp]-=1
                intersection+=1 #교집합 크기 추가
            else: union+=1 #합집합 크기 추가
    print(intersection, union)           
    if union==0 and intersection==0: return 65536
    else: return int((intersection/union)*65536)