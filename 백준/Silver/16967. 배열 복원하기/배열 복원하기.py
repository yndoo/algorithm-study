import sys
myinput = sys.stdin.readline
H, W, X, Y = map(int, myinput().split())

arrB = [list(map(int, myinput().split())) for _ in range(H+X)]
arrA = [[0]*W for _ in range(H)]

for i in range(H):
    for j in range(W):
        if i<X or j<Y:
            arrA[i][j] = arrB[i][j]
        else:
            arrA[i][j] = arrB[i][j] - arrA[i-X][j-Y]

for i in range(H):
    print(' '.join(map(str,arrA[i])))