def solution(board, moves):
    answer = 0
    basket=[]
    for m in moves:
        for i in range(len(board[0])):
            if board[i][m-1]!=0:
                basket.append(board[i][m-1])
                board[i][m-1]=0
                if len(basket)>1 and basket[-1]==basket[-2]:
                    answer+=2
                    basket.pop()
                    basket.pop()
                break       
    return answer