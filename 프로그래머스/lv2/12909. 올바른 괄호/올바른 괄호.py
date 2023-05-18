def solution(s):
    answer = True
    left = 0
    for x in list(s):
        if x =="(": left+=1
        elif x == ")" and left>0 : left-=1
        else: return False
        
    if left==0: return True
    else: return False