def decompress_length(compressed_string):
    stack = []
    for char in compressed_string:
        if char.isdigit():
            stack.append(int(char))
        elif char == '(':
            stack.append(char)
        elif char == ')':
            substr = []
            while stack and stack[-1] != '(':
                substr.append(stack.pop())
            stack.pop()  # '(' 제거
            k = stack.pop()  # 반복 횟수
            stack.extend(substr[::-1] * k)
        else:
            stack.append(char)
    
    return len(stack)

# 예제 입력
compressed_string = input().strip()
print(decompress_length(compressed_string))


