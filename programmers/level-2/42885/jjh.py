def solution_1(people, limit):
    # 구명보트 최대 2명, 무게 제한
    # 구명보트 최대한 적게 사용하여 모든 사람 구출. 구명보트 개수의 최솟값?
    # 어떻게 최대한 적게 사용할 수 있을까?
    # 몸무게 가장 적게 나가는 사람과 가장 많은 사람 조합 우선

    # 무게 오름차순 정렬
    people.sort()
    light = 0
    heavy = len(people) - 1
    boats = 0
    
    while light <= heavy:
        if people[light] + people[heavy] <= limit:
            light 
        heavy -= 1
        light += 1

    return boats
