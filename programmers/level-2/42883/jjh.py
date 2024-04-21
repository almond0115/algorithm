def solution(number, k):
    stack = []
    # 스택에 큰 수만 넣어주기
    for num in number:
        # 스택의 top 값과 num 값 비교
        while k and stack and stack[-1] < num:
            stack.pop()
            k -= 1
        stack.append(num)

    # 남은 k 자리수 뒤에서부터 제거
    return ''.join(stack[:len(stack) - k])