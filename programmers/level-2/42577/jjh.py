def solution_1(pb):
    for i in range(len(pb)):
        for j in range(len(pb)):
            # 전화 번호가 동일 인덱스일 경우 continue
            if pb[i] == pb[j]:      
                continue
            # j 인덱스 값 안에 i 인덱스 값이 존재할 경우
            elif pb[i] in pb[j]:
                pb_length = len(pb[i])
                # 접두사 일 경우
                if pb[i] == pb[j][0:pb_length] :
                    return False
    
    return True

def solution_2(pb):
    pick_list = []
    
    # 최소값 저장
    p_min = min(pb)
    p_length = len(p_min)
    
    while True:
        if len(pb) == 0:
            break
        for i in range(len(pb)):
            if p_min == pb[i]:
                continue
            pick_list.append(pb[i][0:p_length])
            
        if p_min in pick_list:
            return False

        # 최소값 제거
        pb.remove(p_min)
        
    return True

def solution_3(pb):
    for nums in pb:
        arr = ""
        for num in nums:
            arr += num
            if arr in pb and arr != nums:
                return False 






