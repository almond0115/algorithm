from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        # 완전 이진 트리가 되는 모든 경우의 수 -> 재귀

        # N = 1 일 경우, 루트 노드
        if n == 1:
            return [TreeNode(0)]
        
        # 노드 Level 별 순회
        result = []
        for i in range(1, n, 2):
            left_trees = self.allPossibleFBT(i)
            right_trees = self.allPossibleFBT(n-i-1)

            for left_tree in left_trees:
                for right_tree in right_trees:
                    root = TreeNode(0)
                    root.left = left_tree
                    root.right = right_tree
                    result.append(root)

        return result