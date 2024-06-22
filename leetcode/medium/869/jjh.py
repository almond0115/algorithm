from itertools import permutations

def is_power_of_two(n):
    if n <= 0:
        return False
    while n % 2 == 0:
        n /= 2
    return n == 1
    
class Solution_1:
    def reorderedPowerOf2(self, n: int) -> bool:
        # 주어진 문자열의 문자들을 조정하여 2의 거듭제곱 있으면 true, 아니면 false
        # str_n = []
        # for each in str(n):
        #     str_n.append(each)

        digits = list(str(n))
        for perm in permutations(digits):
            if perm[0] != '0':  # 앞자리가 0이 아닌지 확인
                num = int(''.join(perm))
                if is_power_of_two(num):
                    return True
        return False

class Solution_2:
    def reorderedPowerOf2(self, n: int) -> bool:
        # 제한 조건에서 최대 10억이므로 2의 30승까지 배열에 정리
        power_of_twos = [str(1 << i) for i in range(31)]
        # 2의 30승까지 값들을 정렬하여 n 탐색 전 세팅
        sorted_pOf2 = [''.join(sorted(p)) for p in power_of_twos]

        # n 값을 정렬
        sorted_n = ''.join(sorted(str(n)))
        return sorted_n in sorted_pOf2 