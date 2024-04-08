def solution_1(numbers):
    answer = 0
    # 0 ~ 9 순회
    for num in range(10):
        # numbers 배열 수와 같다면 continue
        if num in numbers:
            continue
        answer = answer + num
    return answer

def solution_2(numbers):
    return 45 - sum(numbers)