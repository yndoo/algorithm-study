import sys
input = sys.stdin.readline

N = int(input())
graph=[]
for _ in range(N):
    graph.append(list(map(int,input().split())))

minn=100000
def back(lst):
    global minn
    if (len(lst)==N/2):
        ssum=0
        rsum=0
        rlst=[]
        #==========lst가 스타트팀, 아닌게 링크팀, 각 합의 차를 구해서 최솟값비교==========
        #스타트팀 합
        for i in lst:
            for j in lst:
                if(i==j): continue
                ssum+=graph[i][j]
        #링크팀 리스트 rlst 만들기
        for x in range(N):
            if x not in lst:
                rlst.append(x)
        #링크팀 합
        for i in rlst:
            for j in rlst:
                if(i==j): continue
                rsum+=graph[i][j]
        #최솟값과 비교
        if minn > abs(ssum-rsum):
            minn = abs(ssum-rsum)
        return
    #두명씩 팀짜기위해 뽑기
    for i in range(N):
        if len(lst)==0:
            lst.append(i)
            back(lst)
            lst.pop()
        elif i not in lst and i>lst[-1]:
            lst.append(i)
            back(lst)
            lst.pop()

back([])
print(minn)