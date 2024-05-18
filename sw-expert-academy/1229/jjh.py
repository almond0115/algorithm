crypto_length = int(input())
crypto_list = list(map(int, input().split()))
cmd_num = int(input())
cmd_list = list(map(str, input().split()))

idx = 0
# 명령어 리스트에서 명령어 개별 추출
while cmd_list:
    if cmd_list[idx] == 'I':
        insert_pos = int(cmd_list[idx + 1])                 
        y_num = int(cmd_list[idx + 2])                      
        y_list = list(map(int, cmd_list[idx+3:(idx+3+y_num)]))
        crypto_list[insert_pos:insert_pos] = y_list
        del cmd_list[idx:(idx+3+y_num)]
    elif cmd_list[idx] == 'D':
        del_pos = int(cmd_list[idx +1])
        y_num = int(cmd_list[idx + 2])
        del crypto_list[del_pos:(del_pos+y_num)]
        del cmd_list[idx:(idx+3)]

# 결과 출력
print(*crypto_list[:10])
