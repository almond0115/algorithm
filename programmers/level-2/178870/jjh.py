def solution(sequence, k):
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