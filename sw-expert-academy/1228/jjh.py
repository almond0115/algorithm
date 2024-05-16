crypto_length = int(input())
crypto_list = list(map(int, input().split()))
# 명령어 개수
cmd_num = int(input())
# 명령어 리스트
cmd_list = list(map(str, input().split()))

while True:
    if cmd_num == 0:
        print(*crypto_list[:10])
        break
    # 명령어 리스트에서 명령어 개별 추출
    while True:
        if len(cmd_list) == 0:
            break
        idx = 0
        if cmd_list[idx] == 'I':
            insert_pos = int(cmd_list[idx+1])
            y_num = int(cmd_list[idx+2])
            y_list = map(int, cmd_list[idx+3:(idx+3+y_num)])

            # 암호문에 명령어 수행
            crypto_list[insert_pos:insert_pos] = y_list
            del cmd_list[idx: (idx+3+y_num)]
    
    cmd_num -= 1