from collections import defaultdict

def solution(n, wires):
    # 트리 defaultdict를 통해 초기화
    graph = defaultdict(list)
    
    for x, y in wires:
        graph[x].append(y)
        graph[y].append(x)

    # 전선을 삭제하고 나누어진 트리 개수 탐색 
    def dfs(start, removed_edge, visited):
        count  = 1
        # 시작 노드 방문 배열 추가
        visited.add(start)
        # 시작 노드에 연결되어 있는 노드들 dfs 탐색
        for node in graph[start]:
            # 방문 처리가 되지 않거나, 나눈 간선에 포함되지 않을 경우
            if node not in visited and (start, node) != removed_edge:
                count += dfs(node, removed_edge, visited)
        return count
    
    # 송전탑 개수가 100개 이하이므로 float('inf') 를 사용하는 것이 효율적
    # 최소값이나 최대값을 찾을 때는 float('inf') or -float('inf')를 사용
    # min_diff = 123456789
    min_diff = float('inf')

    # 트리 나누는 경우
    for wire in wires:
        # 삭제할 전선 초기화
        removed_edge = (wire[0], wire[1])
        # set 객체의 방문배열 초기화
        visited = set()
        # 나눈 전선의 왼쪽부터 시작하는 전선의 개수 dfs 탐색
        cnt_left = dfs(wire[0], removed_edge, visited)
        cnt_right = n - cnt_left
        min_diff = min(min_diff, abs(cnt_left - cnt_right))
    
    return min_diff