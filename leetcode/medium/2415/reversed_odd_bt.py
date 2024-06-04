from typing import Optional
# Definition for a binary node
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 1. level order traversal
        nodes = []
        level = [root]
        idx = 0

        while level:
            if idx % 2 == 0:
                nodes.append(level)
            else:
                nodes.append(level[::-1])

            level = [child for node in level for child in (node.left, node.right) if child]
            idx += 1

        for i in range(len(nodes) - 1):
            for j in range(len(nodes[i])):
                nodes[i][j].left = nodes[i+1][2*j]
                nodes[i][j].right = nodes[i+1][2*j+1]

        return nodes[0][0]

            

