from collections import deque, defaultdict

def solution(n, vertex):
    # 그래프 초기화 및 데이터 저장
    graph = defaultdict(list)

    for a, b in vertex:
        graph[a].append(b)
        graph[b].append(a)

    # BFS 초기 세팅
    queue = deque([1])
    distances = [-1] * (n+1)
    distances[1] = 0

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if distances[neighbor] == -1: 
                distances[neighbor] = distances[node] + 1
                queue.append(neighbor)
        
    max_distances = max(distances)

    return distances.count(max_distances)

