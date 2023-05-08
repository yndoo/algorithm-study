def solution(today, terms, privacies):
    answer = []
    myterm={}
    #오늘 날짜 정리
    year,month,day = map(int,today.split("."))
    #약관 종류 정리(딕셔너리 활용)
    for term in terms:
        t,m = term.split()
        myterm[t]=int(m)
    #개인정보 수집 일자별 처리
    for i, p in enumerate(privacies):
        date, term = p.split()
        y,m,d=map(int,date.split("."))
        y= y+(m+myterm[term])//12 if (m+myterm[term])%12 else y+(m+myterm[term])//12 -1
        m= (m+myterm[term])%12 if (m+myterm[term])%12 else 12
        d-=1
        if d==0:
            m-=1
            d=28
        print(y,m,d)
        #오늘 날짜와 비교
        if year<y: 
            continue
        elif year>y:
            answer.append(i+1)
        elif y==year:
            if month<m:
                continue
            elif month>m:
                answer.append(i+1)
            elif month==m:
                if day<=d:
                    continue
                elif day>d:
                    answer.append(i+1)            
    return answer