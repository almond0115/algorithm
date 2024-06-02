def solution_1(clothes):
    # [의상의 이름, 의상의 종류]
    # 의상 경우의 수?
    answer = 1
    categories = {}
    
    for value in clothes:
        categories[value[1]] = 0
    
    for value in clothes:
        categories[value[1]] += 1

    for num in categories.values():
        answer *= (num+1)
        
    
    return answer - 1

from collections import defaultdict

def solution_2(clothes):
    # 종류별로 딕셔너리 초기화
    categories = defaultdict(int)
    
    # 각 의상 종류별로 개수 세기
    for value in clothes:
        categories[value[1]] += 1
        
    # 각 종류 별 (선택하지 않는 경우 포함) 경우의 수 곱하기  
    answer = 1
    for num in categories.values():
        answer *= (num + 1)
    
    # 아무 의상도 선택하지 않는 경우를 제외
    return answer - 1

def solution_3(clothes):
    categories = {}

    # 각 의상 종류별로 개수 세기
    for value in clothes:
        if value[1] not in categories:
            categories[value[1]] = 0
        categories[value[1]] += 1

    # 각 종류별 (선택하지 않는 경우 포함) 경우의 수를 곱하기
    answer = 1
    for num in categories.values():
        answer *= (num + 1)

    # 아무 의상도 선택하지 않는 경우를 제외
    return answer - 1