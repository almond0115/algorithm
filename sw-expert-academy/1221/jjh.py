tc, e_num = input().split()

# 0 ~ 9 의 값
e_list = ["ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"]
sorted_list = []

data = list(map(str, input().split())) 

print(sorted(data, key=lambda x: e_list.index(x)))

# data = list(input().split())

# 정렬 위한 0~9 인덱스 값 저장
# for i in range(int(e_num)):
#     data[i] = e_list.index(data[i])

# data.sort()
# for i in range(int(e_num)):
#     data[i] = e_list[data[i]]

# print(*data)