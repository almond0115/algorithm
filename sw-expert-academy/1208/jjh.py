# dump_num = int(input())
# box_height_list = list(map(int, input().split()))
# max_num, min_num = float('-inf'), float('inf')

# while True:
#     if dump_num == 0:
#         print(max_num - min_num)
#         break

#     # 가장 높은 박스와 가장 낮은 박스 찾기
#     max_num = max(box_height_list)
#     min_num = min(box_height_list)
    
#     print("max_num: ", max_num, " min_num: ", min_num)

#     # 평탄화 작업 수행
#     box_height_list[box_height_list.index(max_num)] -= 1
#     box_height_list[box_height_list.index(min_num)] += 1

#     dump_num -= 1

T = 10
for tc in range(1, T +1):
    N = int(input())
    numbers = list(map(int, input().split()))
    for i in range(N):
        max_num = max(numbers)
        min_num = min(numbers)
        index_max_num = numbers.index(max_num)
        index_min_num = numbers.index(min_num)
        numbers[index_max_num] -= 1
        numbers[index_min_num] += 1
    print('#{} {}'.format(tc, max(numbers)-min(numbers)))