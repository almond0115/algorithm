def solution(s, n):
    answer = ''
    for word in s:
        if word.isupper():
            answer += (((ord(word) - ord("A")) + n) % 26) + ord("A")
        elif word.islower():
            answer += (((ord(word) - ord("a")) + n) % 26) + ord("a")
        else :
            answer += word
            
    return answer
