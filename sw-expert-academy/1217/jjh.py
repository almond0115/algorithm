n, m = map(int, input().split())

def go(n, m):
    if m == 1:
        return n
    else:
        return n * go(n, m-1)

result = go(n, m)

print(result)