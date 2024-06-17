from itertools import combinations

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.combi = list(combinations(characters, combinationLength))
        self.curr_idx = 0
    
    def next(self) -> str:
        result = ''.join(self.combi[self.curr_idx])
        self.curr_idx += 1
        return result
    
    def hasNext(self) -> bool:
        if self.curr_idx >= len(self.combi):
            return False
        else:
            return True

# CombinationIterator -> "abc", 2

# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()