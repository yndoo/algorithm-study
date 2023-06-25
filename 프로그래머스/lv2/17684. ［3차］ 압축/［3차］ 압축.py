def solution(msg):
    answer = []
    mydict = {}
    i=0
    w = msg[0]
    while i<len(msg):
        if i+1<len(msg):
            c = msg[i+1]
        else:
            c=''
        if w+c in mydict.keys():
            if i==len(msg)-1:
                answer.append(mydict[w])
                i+=1
            else:
                w = w+c
                i+=1
        else:
            mydict[w+c] = 27+len(mydict)
            if len(w)==1:
                answer.append(ord(w)-64)
            else:
                answer.append(mydict[w])
            w = c
            i+=1
            
    return answer