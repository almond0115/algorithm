class SmallestInfiniteSet:

    def __init__(self):
        self.t = set(range(1, 1001))

    def popSmallest(self) -> int:
        # 최소 숫자 제거하기
        s = min(self.t)
        self.t.discard(s)
        return s

    def addBack(self, num: int) -> None:
        # 리스트에 값 없을 경우
        if num not in self.t:
            self.t.add(num)
            return True
        else:
            return False