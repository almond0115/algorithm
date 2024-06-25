import heapq

# min을 이용한 풀이 (시간 초과)
class SeatManager_1:

    def __init__(self, n: int):
        self.n_list = [i for i in range(1, n+1)]
        self.reserve_list = []

    def reserve(self) -> int:
        # 가장 작은 숫자부터 예약
        min_num = min(self.n_list)
        self.reserve_list.append(min_num)
        self.n_list.remove(min_num)
        return min_num

    def unreserve(self, seatNumber: int) -> None:
        # 주어진 시트 숫자 예약 취소
        self.reserve_list.remove(seatNumber)
        self.n_list.append(seatNumber)
        return seatNumber

# 힙을 이용한 풀이
class SeatManager_2:

    def __init__(self, n: int):
        self.reserve_list = list(range(1, n+1))
        heapq.heapify(self.reserve_list)

    def reserve(self) -> int:
        # 가장 작은 숫자부터 예약
        return heapq.heappop(self.reserve_list)

    def unreserve(self, seatNumber: int) -> None:
        # 주어진 시트 숫자 예약 취소
        return heapq.heappush(self.reserve_list, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)

# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)