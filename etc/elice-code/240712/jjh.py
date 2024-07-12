def find_original_sequence(n, subset_sums):
    subset_sums.sort()
    used_sums = {0}  # 시작 부분 합은 항상 0입니다.
    original_sequence = []

    for s in subset_sums:
        if s not in used_sums:
            original_sequence.append(s)
            new_sums = set()
            for us in used_sums:
                new_sums.add(us + s)
            used_sums.update(new_sums)
        
        if len(original_sequence) == n:
            break

    original_sequence.sort()
    return original_sequence

# 입력 받기
n = int(input())
subset_sums = list(map(int, input().split()))

# 원래 수열 찾기 및 출력
original_sequence = find_original_sequence(n, subset_sums)
print(" ".join(map(str, original_sequence)))