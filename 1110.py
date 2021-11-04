target = input()
if (len(target) == 1):
    target += '0'
tmp = target

i = 0
while 1:
    if (len(tmp) == 1):
        tmp += '0'
    tmp = tmp[1] + str(int(tmp[0]) + int(tmp[1]))[-1]
    i += 1
    if (tmp == target):
        break
print(i)
