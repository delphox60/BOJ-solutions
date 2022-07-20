ip1 = input().split()

n = ip1[0]
c = ip1[1]

ip2 = input().split()

result = {}

for i in ip2:
    if i in result.keys():
        result[i] += 1
    else:
        result[i] = 1
    
sorted_result = sorted(result.items(), key = lambda item: item[1], reverse=True)

for pair in sorted_result:
    for i in range(pair[1]):
        print(pair[0], end=" ")

