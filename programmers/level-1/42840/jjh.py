import sys
sys.setrecursionlimit(10 ** 6)

def match_answer(patterns, answers, idx, scores):
    if len(answers) == idx:
        return scores
    
    # 수포자 리스트 전체 순회
    for i in range(3):
        # 해당 인덱스에서 정답 값과 수포자 패턴 값이 같으면 점수 추가 
        if answers[idx] == patterns[i][idx % len(patterns[i])]:
            scores[idx] += 1
    
    # 재귀를 통한 다음 수 완전탐색
    return match_answer(patterns, answers, idx+1, scores)

def solution_1(answers):
    # 수포자 3명 패턴 세팅
    patterns = [[1, 2, 3, 4, 5],
               [2, 1, 2, 3, 2, 4, 2, 5],
               [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    
    # 각 수포자 점수 리스트
    scores = [0, 0, 0]

    scores = match_answer(patterns, answers, 0, scores)

    return [i+1 for i in range(3) if scores[i] == max(scores)]

def solution_2(answers):
    pattern1 = [1, 2, 3, 4, 5]
    pattern2 = [2, 1, 2, 3, 2, 4, 2, 5]
    pattern3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    scores = [0, 0, 0]
    for i in range(len(answers)):
        if answers[i] == pattern1[i%len(pattern1)]:
            scores[0] += 1
        if answers[i] == pattern2[i%len(pattern2)]:
            scores[1] += 1
        if answers[i] == pattern3[i%len(pattern3)]:
            scores[2] += 1

    max_score = max(scores)
    return [i+1 for i in range(3) if scores[i] == max_score]     
