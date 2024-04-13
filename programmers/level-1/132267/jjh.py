def solution_1(a, b, n):
    answer = 0
    # 병 a개당 콜라 b개, 빈 병 n개로 시작 
    
    while n >= a:
        # 빈 병을 새로운 콜라로 바꾼다
        new_cola = n // a * b
        # 새로 받은 콜라와 남은 빈 병을 더하여 n을 갱신한다
        n = new_cola + (n % a)
        # 새로 받은 콜라를 더해준다.
        answer += new_cola

    return answer

# 
def solution_2(a, b, n):
    if n < a:
        return 0
    
    new_cola = n//a * b
    rest_cola = new_cola + (n%a)
    return new_cola + solution_2(a, b, rest_cola)