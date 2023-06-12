def solution(want, number, discount):
    answer = 0
    for i in range(len(discount)-10+1):
        for w in range(len(want)):
            if number[w]>discount[i:i+10].count(want[w]): break
        else: answer+=1
    return answer