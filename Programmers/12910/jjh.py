def solution(arr, divisor):
    answer = []
    # arr 원소들 중 divisor로 나누어 떨어지는 것을 answer에 추가
    for i in arr:
        if i % divisor == 0:
            answer.append(i)
    # 나누어 떨어지는 값이 없으면 -1
    if len(answer) == 0:
        answer.append(-1)
    # 최종 answer를 오름차순으로 정렬
    answer.sort()
    
    return answer