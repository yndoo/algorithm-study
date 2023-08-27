import sys
myinput = sys.stdin.readline

H, W = map(int, myinput().split())
blocks = list(map(int, myinput().split()))

max_height = 0
answer = 0
tmp = 0
for i in range(W):
    min_height = min(blocks[max_height], blocks[i])
    for j in range(max_height+1, i):
        if min_height - blocks[j]>=0:
            answer += min_height - blocks[j]
            blocks[j] = min_height
    if blocks[max_height]<blocks[i]:
        max_height = i
print(answer)