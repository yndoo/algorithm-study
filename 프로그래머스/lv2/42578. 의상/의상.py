def solution(clothes):
    answer = 1
    clothcnt = {}
    for cloth in clothes: #각 의상 종류의 개수를 dictinary에 저장
        if cloth[1] in clothcnt.keys():
            clothcnt[cloth[1]] +=1
        else:
            clothcnt[cloth[1]] = 1
            
    for i in clothcnt.values(): #의상 종류 개수 +1(입지 않는 경우의 수 추가) 끼리 곱해서
        answer *= (i+1)
    return answer-1 #-1(아무것도 안 입는 경우의 수)하면 전체 경우의 수임.