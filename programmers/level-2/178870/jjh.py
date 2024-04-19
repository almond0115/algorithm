def solution_1(sequence, k):
    p_sum = []
    seq_list = []
    start, end = 0, 0
    
    # 누적합 구현
    for i in range(len(sequence)):
        p_sum.append(sum(sequence[:i+1]))
    
    for start in range(len(sequence)):
        for end in range(len(sequence)):
            if start > end : continue
            if start == end and p_sum[start] == k:
                seq_list.append([0, start])
            if p_sum[end] - p_sum[start] == k:
                seq_list.append([start+1, end])

    seq_list.sort()
    temp = [sl[1] - sl[0] for sl in seq_list]
     
    return seq_list[temp.index(min(temp))]

def solution_2(sequence, k):
    start, end = 0, 0
    left, right = 0, 0
    sum_val = 0
    min_len = float('inf')

    # outer loop 오른쪽 포인터 순회
    while right < len(sequence):
        sum_val += sequence[right]
        
        # 오른쪽 포인터 누적합이 k 다 클 경우
        while sum_val > k:
            # 왼쪽 포인터 빼면서 위치 이동
            sum_val -= sequence[left]
            left += 1

        # 누적합이 k와 같을 경우
        if sum_val == k:
            # 수열의 길이 저장
            curr_len = right - left + 1
            # 수열의 길이 최솟값 구하기
            if curr_len < min_len:
                min_len = curr_len
                start, end = left, right

        right += 1
    return [start, end]