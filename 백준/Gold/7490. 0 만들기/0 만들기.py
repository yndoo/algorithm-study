import sys
import re
from collections import deque
myinput = sys.stdin.readline

T = int(myinput())

def makingZeros(mystr,i, N):
    if i == N + 1:
        sum = 0
        tmpstr = mystr.replace(' ', '')
        signs = deque()
        for sign in re.split('[^\D]', tmpstr):
            if sign:
                signs.append(sign)

        for j, myint in enumerate(re.split('[+,-]', tmpstr)):
            if j == 0:
                sum += int(myint)
            else:
                x = signs.popleft()
                if x == '+':
                    sum += int(myint)
                else:
                    sum -= int(myint)

        if sum == 0:
            res.append(mystr)
        return
    else:
        makingZeros(mystr + ' ' + str(i), i + 1, N)
        makingZeros(mystr + '+' + str(i), i + 1, N)
        makingZeros(mystr + '-' + str(i), i + 1, N)


for t in range(T):
    res = []
    N = int(myinput())
    makingZeros("1",2, N)
    print('\n'.join(res),end='')
    if t!=T-1:
        print("\n ",end='')
