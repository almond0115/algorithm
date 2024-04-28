def solution(s):
    answer = []

    for i in range(len(s)):
        prev = -1
        for j in range(i):
            if s[i] == s[j]:
                prev = j

        answer.append(i - prev if prev != -1 else -1)

    return answer