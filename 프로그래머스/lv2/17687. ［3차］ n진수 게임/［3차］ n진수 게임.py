def conv(n,i):
    #i를 n진수로 변환하는 함수
    alpha = {10:"A",11:"B",12:"C",13:"D",14:"E",15:"F"}
    res = ""
    while i>0:
        if i%n>9:
            res = alpha[i%n]+res
        else:
            res = str(i%n)+ res
        i = i//n
    return res
        
def solution(n, t, m, p):
    answer = ''
    i=0
    cnt=0
    # while 돌면서 0,1,2, ... 의 숫자를 n진수로 변환
    # 변환한 숫자에서 튜브의 턴인 숫자만 answer에 추가
    while True:
        if i==0: tmp = '0'
        else: tmp = conv(n,i)
        for turn in range(len(tmp)):
            if (cnt+turn+1)%m==p%m: #myturn
                answer+=tmp[turn]
            if len(answer)==t:
                return answer
        i+=1
        cnt += len(tmp)
        
    return answer