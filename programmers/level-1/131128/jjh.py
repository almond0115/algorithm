from collections import Counter

def solution_1(X, Y):
    answer = []
    y_list = []
    tmp = 0
    # 중복 제외 값 추출 어떻게?
    # 숫자로 이루어진 문자열 특정 인덱스 숫자 값 어떻게 지우지? 
    # 결국에는 짝꿍이 되면 해당 값 지워주어야 함
    # Y 리스트 분해 필수
    
    # Y 값 분해
    for idx in list(Y):
        y_list.append(idx)
    
    # X와 Y 값 비교
    for word in X:
        # Y에 해당 숫자가 있을 경우
        if word in y_list:
            # 해당 숫자 추가
            answer += word
            # Y에서 해당 숫자 제거
            y_list.remove(word)
    
    # 짝꿍이 없을 경우
    if len(answer) == 0:
        return "-1"
    
    # 0 만 있을 경우
    tmp = sum([int(idx) for idx in answer])
    if tmp == 0:
        return "0"
    
    answer = sorted(answer, reverse=True)
    answer = ''.join(answer)
    return answer

def solution_2(X, Y):
    answer = ''
    # Counter 함수를 통해 문자열 안에 포함된 원소의 개수 구하기
    # & 연산자로 교집합 구하기
    pair_num = Counter(X) & Counter(Y)

    # 예외 처리
    if not pair_num:                # pair_num 에 공통 값이 없는 경우
        return '-1'
    elif list(pair_num) == ['0']:   # 공통 값이 0만 있는 경우
        return '0'
    
    # 역순으로 정렬
    reverse_num = sorted(pair_num, reverse=True)

    # 문자열 곱을 활용한 정답 도출
    for num in reverse_num:
        answer += num * pair_num[num]
    
    return answer