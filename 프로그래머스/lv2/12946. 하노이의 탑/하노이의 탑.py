answer = []
def move(N,start,to):
    global answer
    # N을 start에서 to로 옮기기
    answer.append([start,to])

def hanoi(N, start, to, via):
    if N==1:
        move(1,start,to)
    else:
        hanoi(N-1,start,via,to)
        move(N,start,to)
        hanoi(N-1,via,to,start)

def solution(n):
    global answer
    hanoi(n,1,3,2)
    return answer