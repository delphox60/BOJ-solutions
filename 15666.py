ip = input().split()

N = ip[0]
T = int(ip[1])

nums = input().split()
nums = list(set(list(map(int, nums))))
N = len(nums)


def f(k, result, bef):

    if k == T:
        print(result)
        return

    for i in nums:
        if i >= bef:
            f(k + 1, result + str(i) + ' ', i)
    return


nums.sort()
f(0, "", 0)
