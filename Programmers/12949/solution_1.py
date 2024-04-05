def solution(arr1, arr2):
    answer = [[0] * len(arr2[0]) for _ in range(len(arr1))]
    
    if len(arr1[0]) == len(arr2):
        # arr1 행 순회
        for i in range(len(arr1)):
            # arr2 열 순회
            for j in range(len(arr2[0])):
                # arr1 행과 arr2 열의 동일한 인덱스끼리 곱하여 합한 값을 저장 
                answer[i][j] = sum(arr1[i][k] * arr2[k][j] for k in range(len(arr1[0])))
    
    return answer