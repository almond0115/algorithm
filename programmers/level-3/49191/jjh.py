def solution(n, results):
    # [A, B] : A선수가 B선수에게 이김을 의미
    # 일부 경기 결과 제공 -> 정확하게 순위를 매길 수 있는 선수의 수?
    
    # 승패 기록할 그래프 (nxn 그래프 생성)
    wins = [[False] * n for _ in range(n)]
    
    # 주어진 결과 그래프 반영
    for winner, loser in results:
        wins[winner-1][loser-1] = True
        
    # 플로이드-워셜 알고리즘으로 승패 관계 파악
    # k는 중간 노드, i는 출발 노드, j는 도착 노드
    for k in range(n):
        for i in range(n):
            for j in range(n):
                # i->k, k->j 가 True 이면 i->j도 True
                if wins[i][k] and wins[k][j]:
                    wins[i][j] = True
                    
    # 각 선수에 대해 정확히 순위 매길 수 있는지 확인
    answer = 0
    for i in range(n):
        count = 0
        for j in range(n):
            # i가 j를 이기거나 j가 i를 이긴 경우
            if wins[i][j] or wins[j][i]:
                count += 1
                
        if count == n-1:
            answer += 1
            
    
    return answer