class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # 1~n번이 원을 그리고 1번부터 k 값만큼 순회
        # 재귀, 완전탐색, 큐?
        # 인덱스 조정 어떻게?

        clockwise = [i for i in range(1, n+1)]
        curr_idx = 0

        while len(clockwise) > 1:
            # 새로운 리스트에 저장하는 방식?
            # 인덱스 순회는 어떻게? %를 통해 circle loop 생성
            idx = (curr_idx + k-1) % len(clockwise)
            clockwise.remove(clockwise[idx])
            curr_idx = idx

        return clockwise[0]