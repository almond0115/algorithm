## [[1845] Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/)

Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.

int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.

void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.



## 제한 사항

1. 1 <= n <= 105
2. 1 <= seatNumber <= n
3. For each call to reserve, it is guaranteed that there will be at least one unreserved seat.
4. For each call to unreserve, it is guaranteed that seatNumber will be reserved.
5. At most 105 calls in total will be made to reserve and unreserve.

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/medium/1845/jjh.py)

### TIL

* [1845 Seat Reservation Manager](https://almond0115.tistory.com/entry/LeetCode-1845-Seat-Reservation-Manager/)