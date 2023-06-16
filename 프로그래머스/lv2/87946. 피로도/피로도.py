def solution(k, dungeons):
    answer = -1
    
    def back(nowk, lst, cnt):
        nonlocal answer
        if len(lst)==len(dungeons): #최대치
            answer=len(lst)
            return 1
        for i,dungeon in enumerate(dungeons):
            if i not in lst:
                if nowk - dungeon[0] >= 0:
                    back(nowk-dungeon[1],lst+[i],cnt+1)
        else:
            if answer<cnt: answer=cnt
    back(k, [], 0)
    return answer

