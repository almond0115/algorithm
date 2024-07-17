n = int(input())
c = list(map(int, input().split()))

# 딕셔너리 dp 
dp = dict()
dp[tuple([1] * n)] = 0

queue = [tuple([1] * n)]
queueIndex = 0

while len(queue) > queueIndex:
    v = queue[queueIndex]
    queueIndex += 1
    for i in range(len(v)):
        for j in range(i+1, len(v)):
            u = []
            for k in range(len(v)):
                if k == j:
                    u[i] += v[k]
                else:
                    u.append(v[k])

            u = tuple(sorted(u))
            if u not in dp:
                dp[u] = dp[v] + v[i] * v[j] * (1 - c[n - len(v)])
                queue.append(u)
            else:
                dp[u] = min(dp[u], dp[v] + v[i] * v[j] * (1 - c[n - len(v)]))
print(dp[(n,)])