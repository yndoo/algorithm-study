import sys
import math
myinput = sys.stdin.readline

N, L = map(int, myinput().split())

lst = []
for _ in range(N):
    lst.append(list(map(int,myinput().split())))

lst.sort(key=lambda x:x[0])

answer = 0
last = 0
for s,e in lst:
    if last<s:
        last = s
    while last<e:
        answer += math.ceil((e - last) / L)
        last += L * math.ceil((e-last)/L)


print(answer)