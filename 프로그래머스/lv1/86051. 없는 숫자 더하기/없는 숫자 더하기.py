def solution(numbers):
    arr = [i for i in range(10)]
    arr = set(arr)-set(numbers)
    return sum(arr)