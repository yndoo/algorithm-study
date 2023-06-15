def solution(phone_number):
    answer = ''
    for _ in range(len(phone_number)-4): answer += '*'
    return answer+phone_number[len(phone_number)-4:]