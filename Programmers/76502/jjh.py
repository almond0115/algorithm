def solution(s):
    answer = 0
    def is_right(s):
        # 스택을 이용한 괄호 문자열 판별
        stack = []
        for bracket in s:
            if bracket in ['(', '{', '[']:
                stack.append(bracket)
            else:
                # 스택이 비어있는 경우 False 반환
                if not stack:
                    return False
                # 닫는 괄호와 스택의 마지막 비교 후 제거
                if bracket == ')' and stack[-1] == '(':
                    stack.pop()
                elif bracket == '}' and stack[-1] == '{':
                    stack.pop()
                elif bracket == ']' and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
                
        return not stack
     
    # 문자열 길이 만큼 반복하기
    for i in range(len(s)):
        # 올바른 괄호 문자열 판별하기
        if is_right(s):
            answer += 1
        # 문자열 회전하기
        s = s[1:] + s[0]

    return answer