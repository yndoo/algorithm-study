from collections import deque
def solution(cacheSize, cities):
    answer = 0
    cache = deque()
    for city in cities:
        city = city.lower()
        if city in cache: #캐시히트, 가장 최근 언급된 도시는 가장 뒤로
            cache.remove(city)
            cache.append(city)
            answer+=1
        else: #캐시미스
            answer+=5
            if len(cache)<cacheSize: #캐시 사이즈 되면 캐시에 넣기
                cache.append(city)
            elif cache:
                cache.popleft() #가장 오래 언급되지 않은 데이터 제거
                cache.append(city) #새로 캐시에 저장
    return answer