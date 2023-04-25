def solution(lottos, win_nums):
    answer = []
    zero_cnt, win_cnt = 0, 0
    for lt in lottos:
        if lt in win_nums:
            win_cnt+=1
        elif lt==0:
            zero_cnt+=1
    if win_cnt+zero_cnt==0:    #다 확정 틀렸을 경우
        return [6,6]
    else:    #그렇지 않으면 최고 순위는 이렇다
        answer.append(7-(win_cnt+zero_cnt))
    if win_cnt==0: answer.append(6)   #다 틀렸는데 0인 곳도 틀린 경우
    else: answer.append(7-win_cnt)
    return answer