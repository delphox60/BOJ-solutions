ip = input()
n = int(ip.split()[0])
d = (ip.split()[1])

cnt = 0

for i in range(1, n + 1):
    for j in str(i):
        if d == j:
            cnt += 1
        
print(cnt)