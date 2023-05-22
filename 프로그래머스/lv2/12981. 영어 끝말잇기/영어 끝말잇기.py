def solution(n, words):
    for i,word in enumerate(words):
        if i==0: continue
        if word[0] != words[i-1][-1] or word in words[:i]:
            return [i%n+1, i//n+1]                   
    else: return [0,0]