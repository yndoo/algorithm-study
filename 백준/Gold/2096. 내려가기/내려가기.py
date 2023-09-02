import sys
import copy
myinput = sys.stdin.readline

N = int(myinput())
minG = [[0]*3 for _ in range(2)]
maxG = [[0]*3 for _ in range(2)]

lst = list(map(int, myinput().split()))
if(N==1):
    print(max(lst), min(lst))
else:
    minG[0] = copy.deepcopy(lst)
    maxG[0] = copy.deepcopy(lst)
    
    for i in range(1, N):
        tmp = list(map(int, myinput().split()))
        maxG[1][0] = max(maxG[0][0], maxG[0][1]) + tmp[0]
        minG[1][0] = min(minG[0][0], minG[0][1]) + tmp[0]
        maxG[1][1] = max(maxG[0][0], maxG[0][1], maxG[0][2]) + tmp[1]
        minG[1][1] = min(minG[0][0], minG[0][1], minG[0][2]) + tmp[1]
        maxG[1][2] = max(maxG[0][1], maxG[0][2]) + tmp[2]
        minG[1][2] = min(minG[0][1], minG[0][2]) + tmp[2]
        minG[0] = copy.deepcopy(minG[1])
        maxG[0] = copy.deepcopy(maxG[1])
    print(max(maxG[1]), min(minG[1]))