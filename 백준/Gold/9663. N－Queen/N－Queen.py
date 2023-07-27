import sys
myinput = sys.stdin.readline

N= int(myinput())
col = [0] * (N+1)
answer = 0

def isokay(i,col):
    k = 1
    while k<i:
        if abs(col[i]-col[k])==abs(i-k) or (col[i]==col[k]):
            return False
        k+=1
    return True

def finding(i, col):
    global answer
    if isokay(i,col):
        if i == N:
            answer += 1
        else:
            for j in range(1,N+1):
                col[i+1]=j
                finding(i+1,col)

finding(0, col)
print(answer)