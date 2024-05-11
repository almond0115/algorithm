t_length = int(input())
magnet_map = [list(map(int, input().split())) for _ in range(t_length)]
stuck_num = 0

# 1 : N극, 2 : S극
# stack으로 교착상태 판별 

# for i in range(t_length):
#     stack = []
#     for j in range(t_length):
#         if magnet_map[j][i] == 1:
#             stack.append(1)
#         elif magnet_map[j][i] == 2:
#             if stack and stack[-1] == 1:
#                 stack.pop()
#                 stuck_num += 1

# print(stuck_num)    

cnt = 0
for j in range(t_length):  # (0,j) 열탐색
    r, c = 0, j
    stack = []
    # 아래로 내려가면서 <1--2> 의 순서이면 체킹
    while r < t_length:
        if not stack and magnet_map[r][c] == 1:  # 스택이 비어있는 상태이면서 1 이면 stack에 넣음
            stack.append(1)
        elif stack and magnet_map[r][c] == 2:  # 스택에 1이 있는 상태에서 2가 나오면 pop 해서 cnt에 더해주기
            cnt += stack.pop()
        r += 1  # 아래로 진행하기 위해 row 인덱스 증가시켜주기

print(cnt) 