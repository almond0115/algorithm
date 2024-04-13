from itertools import combinations

def solution_1(numbers):
    answer = []

    # 조합으로 2개를 뽑는 경우의 수 저장 
    num = list(combinations(numbers, 2))

    # 중복된 수 제거
    for ans in num:
        if sum(ans) in answer:
            continue
        answer.append(sum(ans))
        
    return sorted(answer)

def solution_2(numbers):
    return sorted(set(sum(pair) for pair in combinations(numbers, 2)))