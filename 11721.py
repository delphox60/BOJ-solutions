str = input()

for i in range(len(str)):
    print(str[i], end="")
    if (i + 1) % 10 == 0:
        print()
