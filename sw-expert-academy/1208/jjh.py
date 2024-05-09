dump_num = int(input())
box_height_list = list(map(int, input().split()))

while dump_num:

    # 가장 높은 박스와 가장 낮은 박스 찾기
    max_num = max(box_height_list)
    min_num = min(box_height_list)

    # 평탄화 작업 수행
    box_height_list[box_height_list.index(max_num)] -= 1
    box_height_list[box_height_list.index(min_num)] += 1

    dump_num -= 1

print("max_num - min_num: ", max(box_height_list) - min(box_height_list))

