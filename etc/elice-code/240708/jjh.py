from itertools import permutations

n = input()
answer = []

# 모든 순열 값 구하기
perm = permutations(n)

for p in perm:
    # n의 정수 값보다 정수로 변환된 순열 값이 클 경우
    if int(''.join(p)) > int(n):
        answer.append(int(''.join(p)))

# 오름차순 정렬
answer = sorted(answer)

# 가장 작은 수
print(answer[0])