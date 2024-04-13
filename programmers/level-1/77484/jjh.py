def solution_1(lottos, win_nums):
    answer = []
    correct = 0
    zero = 0
    for i in lottos:
        if i == 0:
            zero += 1
        elif i in win_nums:
            correct += 1
    
    answer.append(7 - (correct + zero) if correct + zero > 1 else 6)
    answer.append(7 - correct if correct > 1 else 6)

    return answer

def solution_2(lottos, win_nums):
    answer = []
    w_num = len(list(filter(lambda x: x in win_nums, lottos)))
    z_num = lottos.count(0)
    answer.append(7 - (w_num + z_num) if w_num + z_num > 1 else 6)
    answer.append(7 - w_num if w_num > 1 else 6)
    return answer
