def solution(arr1, arr2):
    answer = []
    for i in range(len(arr1)): #arr1의 행 개수
        res = []
        for x in range(len(arr2[0])): #arr2의 열 개수
            sum=0
            for j in range(len(arr1[0])): #arr1의 열 개수 == arr2의 행 개수
                sum += arr1[i][j] * arr2[j][x]
            res.append(sum)
        answer.append(res)
    return answer #결과는 arr1행개수 X arr2열개수