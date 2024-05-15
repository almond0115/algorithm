pwd = list(map(int, input().split()))

while True:
    for j in range(1, 6):
        if pwd[0] - j <= 0:
            pwd[0] = 0
            pwd = pwd[1:8] + pwd[0:1]
            break
        pwd[0] = pwd[0] - j 
        pwd = pwd[1:8] + pwd[0:1]
        print(pwd)
    
    if pwd[7] == 0:
        break

print(pwd)