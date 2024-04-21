def solution(n):
    return min([x for x in range(2, n+1) if n%x == 1])