from itertools import permutations

def is_power_of_two(n):
    if n <= 0:
        return False
    while n % 2 == 0:
        n /= 2
    return n == 1
    
class Solution:
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