def solution(a, b):
    answer = ''
    days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    month_days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    # 2016년 1월 1일은 금요일
    # 1월 1일부터 a월 b일까지의 날짜를 구한다
    days_sum = 0
    for i in range(a-1):
        days_sum += month_days[i]
    days_sum += b
    
    # 1월 1일이 금요일이므로 금요일부터 days_sum일까지의 요일을 구한다
    answer = days[(days_sum + 4) % 7]
    return answer