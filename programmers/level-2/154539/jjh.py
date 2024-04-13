def solution_1(numbers):
    answer = []
    # numbers 리스트를 순회
    for i, num in enumerate(numbers):
        # numbers 이후 값을 저장하는 next 리스트를 생성
        found = 0
        for next_num in numbers[i+1:]:
            if num < next_num:
                answer.append(next_num)
                found = 1
                break
        # numbers 보다 큰 수가 없을 경우 -1 저장
        if found == 0:
            answer.append(-1)
            
    return answer

def solution_2(numbers):
    answer = [-1] * len(numbers)
    # 스택 리스트를 통해 numbers 인덱스를 저장 
    stack = []
    for idx in range(len(numbers)):
        # stack의 top과 numbers 값 비교
        while stack and numbers[stack[-1]] < numbers[idx]:
            answer[stack.pop()] = numbers[idx]
        
        # 스택에 인덱스 정수를 저장합니다
        stack.append(idx)
    return answer

def solution_3(numbers):
    answer = []
    for i in range(len(numbers)-1, -1, -1):
        max_val = -1
        for j in range(i+1, len(numbers)):
            if numbers[i] < numbers[j]:
                max_val = numbers[j]
                break
        answer.append(max_val)
    return answer[::-1]