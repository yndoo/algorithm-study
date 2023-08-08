import sys
myinput = sys.stdin.readline

N= int(myinput())
col = [0] * (N)
answer = 0

def isokay(i):
    k = 0
    while k<i:
        if abs(col[i]-col[k])==abs(i-k) or (col[i]==col[k]):
            return False
        k+=1
    return True

def finding(i):
    global answer
    if i==N:
        answer+=1
    else:
        for j in range(N):
            col[i] = j
            if isokay(i):
                finding(i+1)



finding(0)
print(answer)