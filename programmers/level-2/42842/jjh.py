def solution_1(brown, yellow):
    # 테두리 1줄 - 갈색
    # 중앙 - 노랑
    
    # 노랑의 약수? 둘레?
    # a x b = yellow 가 되는 a, b의 값 구하기
    for i in range(1, yellow+1):
        # 노랑에 현재 노랑의 약수 나눈 값이 0일 경우
        if yellow % i == 0:
            j = yellow / i
        else: 
            continue
        
        s_val = (i*2) + (j*2) + 4
        
        if int(s_val) == brown:
            return [j+2, i+2]
    
    return 0