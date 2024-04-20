def solution(park, routes):
    # 산책 시작 위치 찾기
    for i in range(len(park)):
        for j in range(len(park[i])):
            if park[i][j] == 'S':
                start_row, start_col = i, j
                row, col = start_row, start_col
                break
    
    # 이동 벡터 초기화
    directions = {'E': (0, 1), 'W' : (0, -1), 'S': (1, 0), 'N' : (-1, 0)}

    # 이동 요청 값 순회
    for route in routes:
        direction, distance = route.split()
        distance = int(distance)

        # 1칸씩 이동하면서 이동 위치 판별
        for _ in range(distance):
            # 이동 후 위치 세팅
            curr_row, curr_col = row + directions[direction][0], col + directions[direction][1]
            # 공원 벗어난 경우
            if curr_row < 0 or curr_col < 0 or curr_row >= len(park) or curr_col >= len(park[0]):
                row, col = start_row, start_col
                break
            # 장애물 만난 경우
            if park[curr_row][curr_col] == 'X':
                row, col = start_row, start_col
                break
            row, col = curr_row, curr_col
        start_row, start_col = row, col

    return [row, col]