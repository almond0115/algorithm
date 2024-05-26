# 정확성: 25.8
# 효율성: 0.0
# 합계: 25.8 / 100.0
def solution_1(scoville, K):
    # 모든 음식이 스코필 지수 이상이 될 때까지 반복 
    mix_cnt = 0
    
    while True:
        # 음식 정렬
        scoville.sort()
        
        # 음식 섞기
        new_sc = scoville[0] + (scoville[1] * 2)
        scoville.pop(0) 
        scoville.pop(1)
        scoville.append(new_sc)
        
        # 가장 작은 원소가 스코빌 지수 이상일 경우 break
        if scoville[0] >= K:
            break
        
        mix_cnt += 1
    
    
    return mix_cnt

# 정확성: 71.0
# 효율성: 0.0
# 합계: 71.0 / 100.0
def solution_2(scoville, K):
    # 모든 음식이 스코필 지수 이상이 될 때까지 반복 
    mix_cnt = 0
    
    while True:
        # 가장 작은 원소가 스코빌 지수 이상일 경우 break
        if min(scoville) >= K:
            break
        min_sc_a = min(scoville)
        scoville.remove(min_sc_a)
        min_sc_b = min(scoville)
        scoville.remove(min_sc_b)
        
        
        # 음식 섞기
        new_sc = min_sc_a + (min_sc_b * 2)
        
        # 섞은 음식 추가
        scoville.append(new_sc)
        
        # 섞은 횟수 추가
        mix_cnt += 1
    
    return mix_cnt

import heapq

def solution_3(scoville, K):
    # 효율적인 최소 값 접근 방식 필요 -> 힙 정렬
    heapq.heapify(scoville)

    # 섞은 횟수
    mix_cnt = 0
    
    # 스코빌 지수 K 이상 만들 수 없는 경우 -1 리턴
    while scoville:
        # 가장 맵지 않은 스코빌 지수 음식 추출
        min_spicy_a = heapq.heappop(scoville)

        # 스코빌 지수가 모두 K 이상일 경우
        if min_spicy_a >= K:
            break

        # 스코빌 지수를 K 이상 만들 수 없는 경우
        if not scoville:
            return -1
        
        min_spicy_b = heapq.heappop(scoville)

        # 음식 섞기
        new_spicy = min_spicy_a + (min_spicy_b * 2)
        heapq.heappush(scoville, new_spicy)
        
        mix_cnt += 1

    return mix_cnt