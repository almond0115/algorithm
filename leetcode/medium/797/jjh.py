from typing import List

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(node, path):
            # Add the current node to the path
            path.append(node)
            
            # If the current node is the target node, add the path to the result
            if node == len(graph) - 1:
                result.append(list(path))
            else:
                # Recur for all the vertices adjacent to this vertex
                for neighbor in graph[node]:
                    dfs(neighbor, path)
            
            # Remove the current node from the path to backtrack
            path.pop()
        
        result = []
        dfs(0, [])
        return result

# Example usage:
graph = [[1, 2], [3], [3], []]
solution = Solution()
print(solution.allPathsSourceTarget(graph))
