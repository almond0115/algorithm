word_map = [list(map(str, list(input()))) for _ in range(100)]
max_length = float('-inf')

# 각 칸에 들어가는 언어 'A', 'B', 'C' 중 하나
# 반복 최소화를 위해 가장 긴 길이부터 역순으로 탐색

# 가로 탐색
for i in range(100):
    for j in range(100):
        for length in range(100, 0, -1):
            if j + length <= 100:
                if word_map[i][j : j + length] == word_map[i][j : j + length][::-1]:
                    max_length = max(max_length, length)


# 세로 탐색
for i in range(100):
    for j in range(100):
        for length in range(100, 0, -1):
            if j + length <= 100:
                if [word_map[k][i] for k in range(j, j+length)] == [word_map[k][i] for k in range(j, j+length)][::-1]:
                    max_length = max(max_length, length)

print(max_length)