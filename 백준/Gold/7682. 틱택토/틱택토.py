mystr = ""
bingo1 = [[0,4,8], [2,4,6]]
bingo2 = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8]]

while True:
    mystr = input()
    if mystr == "end": break
    else:
        Xs = []
        Os = []
        dots = 0
        for i,s in enumerate(mystr):
            if s=='X':
                Xs.append(i)
            elif s=='O':
                Os.append(i)
            else:
                dots+=1
        if len(Xs)==len(Os):
            #개수 같으면 O가 이긴채 끝나야 함 (X빙고있으면 invalid)
            #O도 없으면 invalid
            X, O = 0, 0  # 각각 X, O의 빙고 개수
            # 대각선 확인
            for b in bingo1:
                if set(b) & set(Xs) == set(b):
                    X += 1
                if set(b) & set(Os) == set(b):
                    O += 1
                # 가로, 세로 확인
            for b in bingo2:
                if set(b) & set(Xs) == set(b):
                    X += 1
                if set(b) & set(Os) == set(b):
                    O += 1
            if dots==0: print("invalid") #무조건 dots있어야함
            elif X>0: print("invalid") #X빙고있으면 안됨
            elif O>0: print("valid") #O가 이겼어야 함
            else: print("invalid")

        elif  len(Xs)==len(Os)+1:
            #X가 승리하거나 승리 없이 끝난 경우
            #O에 빙고 있으면 invalid
            #dots가 0이면 빙고 없거나 X에 있어야 함
            #dots>0이면 X에 빙고있어야 함(없거나 O빙고는 invalid), 대각세로빙고 있을 수 없음

            X, O = 0,0 #각각 X대각, X가로세로, O의 빙고 개수
                #대각선 확인
            for b in bingo1:
                if set(b)&set(Xs) == set(b):
                    X+=1
                if set(b)&set(Os) == set(b):
                    O+=1
                #가로, 세로 확인
            for b in bingo2:
                if set(b)&set(Xs) == set(b):
                    X+=1
                if set(b)&set(Os) == set(b):
                    O+=1

            if O>0:
                print("invalid")
                continue
            if dots==0: #X승리하거나 승리없음
                if X>0 or X==0:
                    print("valid")
                else: print("invalid")
            elif dots>0: #X승리
                if X>0: print("valid")
                else: print("invalid")
        else:
            print("invalid")
            continue
