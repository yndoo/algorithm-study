def solution(n, words):
    answer = []
    for i,word in enumerate(words):
        if i==0: continue
        if word[0] != words[i-1][-1] or word in words[:i]:
            print(i, word)
            answer.append(n) if (i+1)%n==0 else answer.append((i+1)%n)
            answer.append((i+1)//n) if (i+1)%n==0 else answer.append((i+1)//n+1)
            return answer
                    
    else: return [0,0]