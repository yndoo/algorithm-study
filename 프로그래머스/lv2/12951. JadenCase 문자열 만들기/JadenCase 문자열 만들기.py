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