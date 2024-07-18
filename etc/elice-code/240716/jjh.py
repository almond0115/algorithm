from heapq import heappop, heappush

MAX = 2000100
INF = int(1e18)
dirY = [-1, 0, 1, 0]
dirX = [0, 1, 0, -1]

def get(y, x):
    return y * N + x

N = int(input())
A = [0] * MAX
for i in range(1, N + 1):
    for j, a in enumerate(map(int, input().split()), start=1):
        A[get(i, j)] = a

elice = [tuple(map(int, input().split())) for _ in range(5)]

v = [list() for _ in range(MAX)]

for i in range(1, N + 1):
    for j in range(1, N + 1):
        current = get(i, j)
        for k in range(4):
            y, x = i + dirY[k], j + dirX[k]
            if y < 1 or y > N or x < 1 or x > N:
                continue

            next_ = get(y, x)
            v[current].append((A[current] + A[next_], next_))

dist = [[INF] * 5 for _ in range(MAX)]

for i in range(5):
    now = get(*elice[i])
    dist[now][i] = 0

    pq = [(dist[now][i], now)]
    while pq:
        curDist, curIndex = heappop(pq)

        for nextDist, nextIndex in v[curIndex]:
            if dist[nextIndex][i] > curDist + nextDist:
                dist[nextIndex][i] = curDist + nextDist
                heappush(pq, (curDist + nextDist, nextIndex))

answer1 = dist[get(1, 1)][0]
for i in range(1, 5):
    answer1 += dist[get(*elice[i])][i - 1]

answer2 = dist[get(1, 1)][4]
answer2 += dist[get(*elice[1])][4]
answer2 += dist[get(*elice[2])][1]
answer2 += dist[get(*elice[3])][2]
answer2 += dist[get(*elice[0])][3]

print(min(answer1, answer2))