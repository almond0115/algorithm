def solution(s):
    answer = []
    zero_cnt = convert_cnt = 0
    
    while s != "1":

        # 문자열 내 0 개수 세기
        zero_cnt += s.count("0")
        # 문자열 0 제거, 길이 계산 후 이진 변환
        s = bin(len(s.replace("0", "")))[2:]
        # 변환 횟수 증가
        convert_cnt += 1

    return [convert_cnt, zero_cnt]