T = int(input())
i = 0

while i < T:
    numbers = input()
    print(int(numbers.split(',')[0])+int(numbers.split(',')[1]))
    i += 1
