def solution(n):
    answer = [num for num in str(n)]
    answer.sort(reverse=True)
    return int(''.join(answer))