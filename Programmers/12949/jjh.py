def solution(arr1, arr2):
    answer = [[]]
    # TypeError: 'list' object cannot be interpreted as an integer 어떻게 해결?
    
    # 2차원 행렬 arr1의 열과 arr2의 행의 길이가 같은지 확인
    if len(arr1[0]) == len(arr2):
        # arr1 행 순회
        for i in range(len(arr1)):
            # arr2 열 순회
            for j in range(len(arr2[0])):
                # arr1 행과 arr2 열 곱을 answer에 저장
                answer[i][j] = sum(arr1[i][ret] * arr2[ret][j] for ret in range(arr1[0]))

    return answer