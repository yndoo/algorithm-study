import sys
myinput = sys.stdin.readline

T = int(myinput())
for _ in range(T):
    W = myinput().rstrip()
    K = int(myinput())
    cnum = dict()
    if K == 1:
        print(1, 1)
        continue
    for i, s in enumerate(W):
        if s in cnum:
            cnum[s].append(i)
        else:
            cnum[s] = [i]
    mymin = 10001
    mymax = -1
    for x in cnum.values():
        if len(x)>=K:
            for i in range(len(x)-K+1):
                if mymin > x[i+K-1]-x[i]+1:
                    mymin = x[i+K-1]-x[i]+1
                if mymax < x[i+K-1]-x[i]+1:
                    mymax = x[i+K-1]-x[i]+1
    if mymin==10001 or mymax == -1: print(-1)
    else: print(mymin, mymax)
