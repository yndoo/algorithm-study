def solution(elements):
    answer = set()
    for i in range(len(elements)): #부분 수열의 길이는 i+1 (1~5)
        newelements = elements+elements[0:i]
        for j in range(len(elements)):
            answer.add(sum(newelements[j:j+i+1]))
    return len(answer)