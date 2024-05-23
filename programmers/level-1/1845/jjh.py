def solution_1(nums):
    max_pick = len(nums) / 2
    pick_list = set()
    
    for num in nums:
        if len(pick_list) == max_pick:
            break
        pick_list.add(num)

    return len(pick_list)

def solution_2(nums):

    return min(len(nums)/2, len(set(nums)))