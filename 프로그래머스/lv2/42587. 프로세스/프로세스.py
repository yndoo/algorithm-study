def solution(priorities, location):
    answer = 0
    ptr = 0
    while answer<len(priorities):
        if  priorities[ptr]==-1:
            ptr = (ptr + 1)%len(priorities)
            continue
        elif priorities[ptr] != max(priorities):
            print(ptr)
            if max(priorities[ptr:]) == max(priorities):
                ptr += priorities[ptr:].index(max(priorities[ptr:]))
            else:
                ptr = priorities.index(max(priorities[:ptr+1]))
        

        answer+=1
        if ptr == location: return answer
        priorities[ptr]=-1
        ptr = (ptr + 1)%len(priorities)
    return answer