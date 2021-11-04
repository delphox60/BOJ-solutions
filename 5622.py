st = input()
result = 0

for i in st:
    if i in 'ABC':
        result += 4
    elif i in 'DEF':
        result += 5
    elif i in 'GHI':
        result += 6
    elif i in 'JKL':
        result += 7
    elif i in 'MNO':
        result += 8
    elif i in 'PQRS':
        result += 9
    elif i in 'TUV':
        result += 10
    elif i in 'WXYZ':
        result += 11

print(result - len(st))
