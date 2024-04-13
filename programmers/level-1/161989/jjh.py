def solution_1(n, m, section):
    answer = 1
    # 롤러로 칠하는 경계 
    roller_end = section[0] + m - 1
    # section 값들을 순회하여 롤러 길이의 끝보다 큰 값이 나오면 다음 영역부터 칠한다 

    for i in range(1, len(section)):
        # 롤러로 칠하는 경계를 벗어나면 새롭게 칠하는 영역을 더해준다
        if roller_end < section[i]:
            roller_end = section[i] + m - 1
            answer += 1

    return answer

