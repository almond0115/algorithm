arr = [list(map(int, input().split())) for _ in range(100)]

max_num = float('-inf')

# 각 행의 합 구하기
for i in range(100):
    row_sum = 0
    for j in range(100):
        row_sum += arr[i][j]
    if row_sum > max_num:
        max_num = row_sum

# 각 열의 합 구하기
for i in range(100):
    col_sum = 0
    for j in range(100):
        col_sum += arr[j][i]
    if col_sum > max_num:
        max_num = col_sum

# 대각선의 합 구하기
left_sum, right_sum = 0, 0
for i in range(100):
    left_sum += arr[i][i]
    right_sum += arr[i][99-i]

if left_sum > max_num:
    max_num = left_sum
elif right_sum > max_num:
    max_num = right_sum

print(max_num)


