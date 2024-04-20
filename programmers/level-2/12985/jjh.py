def solution(n,a,b):
    answer = 0
    
    while a != b:
        a = (a+1) // 2 
        b = (b+1) // 2
        
        answer += 1 
        
        # 만약 n이 홀수일 경우?
        if n%2 != 0:
            n = (n+1) // 2
        else:
            n = n // 2

    return answer