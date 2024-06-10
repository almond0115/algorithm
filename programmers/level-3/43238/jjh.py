def solution(n, times):
    # 모든 사람이 심사를 받는데 걸리는 시간을 최소화
    # 입국 심사 기다리는 사람 최대 10억명
    # n = 6, times = [7, 10]
    # 1-7, 1-10, 8-14, 11-20, 15-21, 22-28 : 6명 심사 최소 시간 28분

    def passport_control(n, times, curr_time):
        if n <= 0:
            return curr_time
        
        min_total_time = float('inf')
        
        for time in times:
            remaining = n - (curr_time // time)
            if remaining < 0 :
                remaining = 0

            min_total_time = min(min_total_time, passport_control(remaining, times, curr_time))
        
        return min_total_time
        
    return passport_control(n, times, 0)

def solution(n, times):
    # 최소로 걸리는 시간과 최대로 걸리는 시간 설정
    left, right = 1, max(times) * n

    while left < right:
        mid = (left + right) // 2
        # mid 시간에 심사 가능한 총 심사 인원
        total = sum(mid // time for time in times)

        # 최적의 시간값을 구할 때까지 이분 탐색
        if total >= n:
            right = mid
        else:
            left = mid + 1
    
    # 최소 값은 left 이므로 left 반환
    return left

