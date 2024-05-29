from itertools import permutations

def is_prime(n):
    # 1 이하는 False
    if n < 2:
        return False

    # 2 ~ 주어진 n 값의 제곱근 값까지 순회
    for i in range(2, int(n**0.5) + 1):
        # 한번이라도 나머지 0이 되는 값이 나온다면 False
        if n % i == 0:
            return False

    return True

def solution_1(numbers):
    # 결과 값인 소수의 개수는 중복 허용 안되는 set 객체로 설정
    possible_numbers = set()

    # 가공된 모든 정수를 저장할 변수는 set 객체로 초기화합니다. 
    for length in range(1, len(numbers) + 1):
        # 순열이 a, b와 b, a가 다르다는 점을 이용해 
        # first Loop에서 정한 글자 수에  맞춰 모든 순열의 경우를 저장합니다.   
        for perm  in permutations(numbers, length):
            # 튜플 형태를 리턴하므로 join을 통해 합치고, 숫자로 변환해야 합니다.
            num = int(''.join(perm))
            # 변환된 숫자를 set 객체에 add 합니다.
            possible_numbers.add(num)

    # 소수 판별 후 소수 값 개수를 리턴합니다.
    prime_cnt = 0
    for p_num in possible_numbers:
        if is_prime(p_num):
            prime_cnt += 1
    
    return prime_cnt

def solution_2(numbers):
    a = set()
    for i in range(len(n)):
        a |= set(map(int, map("".join, permutations(list(n), i + 1))))
    a -= set(range(0, 2))
    for i in range(2, int(max(a) ** 0.5) + 1):
        a -= set(range(i * 2, max(a) + 1, i))
    return len(a)