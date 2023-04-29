from collections import Counter
def solution(participant, completion):
    only = Counter(participant)-Counter(completion)
    return list(only)[0]
    

'''
def solution(participant, completion):
    participant.sort()
    completion.sort()

    while len(completion):
        if participant[0]==completion[0]:
            participant.pop(0)
            completion.pop(0)
        else:
            return participant[0]
    return participant[0]


def solution(participant, completion):
    participant.sort()
    completion.sort()
    print(participant,completion)
    i=0
    while i < len(participant):
        if participant[i] in completion:
            participant.pop(i)
            completion.pop(i)
        else:
            return participant[i]
'''
