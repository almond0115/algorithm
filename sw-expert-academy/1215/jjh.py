# import sys

word_length = int(input())
# 8 x 8 글자판  
word_map = [list(map(str, list(input()))) for _ in range(8)]
count = 0

# 가로 탐색
for i in range(8):
    for j in range(8 - word_length + 1):
        if word_map[i][j:j + word_length] == word_map[i][j:j + word_length][:: - 1]:
            count += 1

# 세로 탐색
for i in range(8):
    for j in range(8 - word_length + 1):
        if [word_map[k][i] for k in range(j, j + word_length)] == [word_map[k][i] for k in range(j, j + word_length)][:: -1]:
            count += 1

print(count)

