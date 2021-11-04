st = input()
result = 0
idx = 0

while idx < len(st):
    if st[idx] == 'c':
        if st[idx + 1] == '=':
            result += 1
            idx += 2
            continue
        elif st[idx + 1] == '-':
            result += 1
            idx += 2
            continue

    elif st[idx] == 'd':
        if st[idx + 1] == 'z' and st[idx + 2] == '=':
            result += 1
            idx += 3
            continue
        elif st[idx + 1] == '-':
            result += 1
            idx += 2
            continue

    elif st[idx:idx+2] == 'lj':
        result += 1
        idx += 2
        continue

    elif st[idx:idx+2] == 'nj':
        result += 1
        idx += 2
        continue

    elif st[idx:idx+2] == 's=':
        result += 1
        idx += 2
        continue

    elif st[idx:idx+2] == 'z=':
        result += 1
        idx += 2
        continue

    idx += 1
    result += 1


print(result)
