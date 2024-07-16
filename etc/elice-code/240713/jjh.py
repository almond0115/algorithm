def find_min_num(n, k):
    cur_num = n+1
    while len(set(str(cur_num))) != k:
        cur_num += 1
    return cur_num

n, k = map(int, input().split())
print(find_min_num(n, k))