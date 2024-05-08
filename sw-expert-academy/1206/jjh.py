b_num = int(input())
b_list = list(map(int, input().split()))
answer = 0

for i in range(2, b_num-2):
    # 2칸 이내에 높은 건물이 있을 경우
    if b_list[i] > b_list[i-1] and b_list[i] > b_list[i-2] and b_list[i] > b_list[i+1] and b_list[i] > b_list[i+2]:
        # 2칸 이내 건물 중 가장 높은 건물 찾기
        max_building = max(b_list[i-1], b_list[i-2], b_list[i+1], b_list[i+2])
        # 가장 높은 건물과 차이만큼 조망권 확보
        answer += b_list[i] - max_building

print(answer)