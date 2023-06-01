from collections import deque
def solution(st):
    answer = 0
    for i in range(len(st)):
        q = deque(st)
        q.rotate(-i)
        s = deque()
        while q:
            if not s: s.append(q.popleft())
            if s[len(s)-1] == "(":
                if q and q[0]==")":
                    q.popleft()
                    s.pop()
                elif q:
                    s.append(q.popleft())
            elif s[len(s)-1] == "{":
                if q and q[0]=="}":
                    q.popleft()
                    s.pop()
                elif q:
                    s.append(q.popleft())
            elif s[len(s)-1] =="[":
                if q and q[0]=="]":
                    q.popleft()
                    s.pop()
                elif q: 
                    s.append(q.popleft())      
            else: break
        if not q and not s: 
            print(i)
            answer+=1        

    return answer