def solution(k, m, score):
    answer = 0
    score_list = []
    # score 정렬 후 내림차순 정렬
    score.sort(reverse=True)
    # score 리스트 내림차순 정렬
    # score.reverse()
    # m개 단위로 리스트 나누기
    for i in range(0, len(score), m):
        score_list.append(score[i:i+m])
    
    # 각 리스트의 가장 작은 값 추출
    for i in range(len(score_list)):
        if len(score_list[i]) == m:
            answer += min(score_list[i])
            
    return answer*m
    
