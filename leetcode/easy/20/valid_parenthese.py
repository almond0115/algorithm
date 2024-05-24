class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ss in s:
            if stack and ((stack[-1] == '(' and ss == ')') or (stack[-1] == '[' and ss == ']') or (stack[-1] == '{' and ss == '}')):
                stack.pop()
                continue 

            stack.append(ss)
    
        if not stack:
            return True
        else:
            return False