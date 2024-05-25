def solution_1(prices):
    # 가격이 떨어지지 않은 기간 구하기
    # 구간 탐색
    answer = [0] * len(prices)
    
    for i in range(len(prices)-1):
        time_cnt = 0
        for j in range(i+1, len(prices)):
            time_cnt += 1
            if prices[i] > prices[j]:
                answer[i] += time_cnt
                break
                
        if answer[i] == 0:
            answer[i] += time_cnt
                
    return answer

