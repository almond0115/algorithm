from collections import defaultdict

def solve():
    import sys
    sys.setrecursionlimit(200000)
    
    N = int(input())
    tree = defaultdict(list)
    
    for _ in range(N - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    
    results = [0] * (N + 1)
    visited = [False] * (N + 1)
    
    def dfs(node):
        visited[node] = True
        is_leaf = True
        lose = False
        
        for neighbor in tree[node]:
            if not visited[neighbor]:
                is_leaf = False
                if dfs(neighbor) == 0:
                    lose = True
        
        if is_leaf:
            results[node] = 1
        else:
            results[node] = 1 if lose else 0
        
        return results[node]
    
    dfs(1)
    
    for i in range(1, N + 1):
        print(results[i])

if __name__ == "__main__":
    solve()
