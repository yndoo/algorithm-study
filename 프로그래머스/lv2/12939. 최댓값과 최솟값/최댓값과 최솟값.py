def solution(s):
    answer = ''
    lst = list(map(int,s.split()))
    minn,maxx=10000000,-10000000
    for x in lst:
        if x < minn:
            minn=x
        if x >maxx:
            maxx=x
    
    return ' '.join(map(str,[minn,maxx]))