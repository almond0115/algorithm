input = __import__("sys").stdin.readline
n, m, l, t = map(int, input().split())
a = [0] * n

for _ in range(m):
    i, j = map(int, input().split())
    for k in range(i-1, j-1):
        a[k] += 1

d = [0] * -~l
c = [0] * -~t

for i in range(n):
    if a[i] >= t:
        while len(c) > 1 and not c[-1]:
            c.pop()
        
        for i in range(len(c) - 1):
            c[i-1] += c[i]

        d = [
            max(d[i-j] + c[j] for j in range(min(i+1, len(c)))) + 1
            for i in range(l + 1)
        ]
        c = [0] * -~t
    else:
        c[t - a[i]] += 1

while len(c) > 1 and not c[-1]:
    c.pop()
for i in range(len(c) - 1):
    c[i+1] += c[i]
d = [max(d[i-j] + c[j] for j in range(min(i+1, len(c)))) for i in range(l+1)]
print(d[-1])
