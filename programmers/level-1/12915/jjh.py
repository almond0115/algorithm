def solution(strings, n):
    answer = []
    # strings의 문자열을 n번째 문자를 기준으로 정렬
    # n번째 문자가 같은 경우 사전 순으로 정렬
    answer = sorted(strings, key=lambda x: (x[n], x))

    return answer