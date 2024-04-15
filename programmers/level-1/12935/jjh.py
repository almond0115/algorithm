def solution(arr):
    # arr 길이 1인 경우
    if len(arr) == 1:
        return [-1]
    # 최소값 제거하여 리턴
    arr.remove(min(arr))
    return arr
