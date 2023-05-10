def solution(s):
    answer = []
    new=''
    for c in list(s):
        if c!=' ':
            new+=c
        else:
            answer.append(new.capitalize())
            new=''
    answer.append(new.capitalize())
    return ' '.join(answer)
    #answer 리스트 사이에 공백을 넣어 return하기 때문에
    #공백이 연속으로 또는 앞뒤에 나왔을 때 빈칸을 answer에 넣어주어 공백을 구현할 수 있습니다.
