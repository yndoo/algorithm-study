def solution(numbers, hand):
    answer = ''
    keypads=[[1,4,7,-1],[2,5,8,0],[3,6,9,-2]]    #-1:*, -2:#
    left, right= [0,3],[2,3]
    for n in numbers:
        if n in keypads[0]:    #확정왼손
            answer+="L"
            for i,num in enumerate(keypads[0]):
                if num==n:
                    left=[0,i]
                    break
        elif n in keypads[2]:    #확정오른손
            answer+="R"
            for i,num in enumerate(keypads[2]):
                if num==n:
                    right=[2,i]
                    break
        elif n in keypads[1]:    #가운데 키패드(비교필요)
            for i,num in enumerate(keypads[1]):
                if num==n:
                    if abs(1-left[0])+abs(i-left[1])<abs(1-right[0])+abs(i-right[1]): #왼가깝
                        answer+="L"
                        left=[1,i]
                    elif abs(1-left[0])+abs(i-left[1])>abs(1-right[0])+abs(i-right[1]): #오른가깝
                        answer+="R"
                        right=[1,i]
                    else: #같으면 hand 보기
                        if hand=="right":
                            answer+="R"
                            right=[1,i]
                        else:
                            answer+="L"
                            left=[1,i]
            
    return answer