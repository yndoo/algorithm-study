def solution(brown, yellow):
    w, h = 0, 0 #노란 카펫의 가로, 세로 길이
    #2(w+h)+4 = brown, w*h=yellow, w+2, h+2가 카펫 가로, 세로 길이임을 이용
    brown = (brown-4)//2 #w+h
    for i in range(brown-1,0,-1):
        if yellow%i==0 and yellow//i==brown-i:
            return [i+2,brown-i+2]