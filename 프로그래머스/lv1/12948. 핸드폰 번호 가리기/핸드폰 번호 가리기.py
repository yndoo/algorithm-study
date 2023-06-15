def solution(phone_number):
    answer = ''
    for _ in range(len(phone_number)-4): answer += '*'
    return answer+phone_number[len(phone_number)-4:]

'''
def solution(phone_number):
    return '*'*(len(phone_number)-4) + phone_number[len(phone_number)-4:]
'''
