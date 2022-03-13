def isHansu(num):
    s = str(num)

    if (len(s) == 1):
        return True

    dif = int(s[1]) - int(s[0])

    for i in range(1, len(s)):
        if int(s[i]) - int(s[i - 1]) != dif:
            return False

    return True


n = int(input())

result = 0

for i in range(1, n + 1):
    if isHansu(i):
        result += 1

print(result)
