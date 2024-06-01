from collections import deque

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def solution(maps):
    # 최단 거리를 구하는 문제 -> BFS
    # 먼저 주어진 map 행, 열 길이 저장
    n, m = len(maps), len(maps[0])

    # deque 객체 생성, 시작 좌표 생성
    queue = deque([(0, 0)])
    
    # queue 객체 길이만큼 순회
    while len(queue):
        # queue 왼쪽 값부터 꺼내기
        y, x = queue.popleft()
        
        # 상, 하, 좌, 우 4가지 방향 값 순회
        for i in range(4):
            # 다음 좌표 위치로 이동 
            ny, nx = y + dy[i], x + dx[i]
            
            # 이동된 좌표가 주어진 map을 벗어나거나 벽이 있는 자리일 경우 continue
            if ny <= 0 or nx <= 0 or ny > n or nx > m or maps[ny][nx] == 0:
                continue

            # 이동된 좌표에 이전 좌표 값 추가
            maps[ny][nx] += maps[y][x]
            # 큐에 이동된 좌표 추가
            queue.append((ny, nx))

    return -1 if maps[n-1][m-1] == 1 else map[n-1][m-1]