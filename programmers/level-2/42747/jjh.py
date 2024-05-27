def solution_1(citations):
    # citations : 과학자가 발표한 논문의 인용 횟수
    # 논문 n 편 중 h번 이상 인용된 논문이 h편 이상 나머지 h편 이하
    # h의 최댓 값? -> H-Index

    max_h = 0
    
    for i in range(1, len(citations) + 1):
        c_num = 0
        for citation in citations:
            if citation >= i:
                c_num += 1
                
        if c_num <= i:
            max_h = max(max_h, c_num)
        
    return max_h

def solution_2(citations):
    # citations : 과학자가 발표한 논문의 인용 횟수
    # 논문 n 편 중 h번 이상 인용된 논문이 h편 이상 나머지 h편 이하
    # h의 최댓 값? -> H-Index
    
    citations.sort(reverse=True)
    
    for h in range(len(citations)):
        if h >= citations[h]:
            return h
    return len(citations)

def solution_3(citations):
    citations.sort(reverse=True)
    # [3, 0, 6, 1, 5]일 경우
    # 1 3 / 2 0 / 3 6 / 4 1 / 5 5 튜플들에서 min 값은 최소한의 논문 인용 횟수입니다.
    # 그중 max 값을 answer에 저장
    answer = max(map(min, enumerate(citations, start=1)))
    return answer