import sys
myinput = sys.stdin.readline

T = int(myinput())
for _ in range(T):
    N = int(myinput())
    stickers = [list(map(int, myinput().split())) for _ in range(2)]
    if N==1:
        print(max(stickers[0][0], stickers[1][0]))
    else:
        stickers[0][1] += stickers[1][0]
        stickers[1][1] += stickers[0][0]
        for j in range(2, N):
            stickers[0][j] += max(stickers[1][j-1], stickers[1][j-2])
            stickers[1][j] += max(stickers[0][j-1], stickers[0][j-2])
        print(max(stickers[0][N-1], stickers[1][N-1]))