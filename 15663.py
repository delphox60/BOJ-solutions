ip = input().split()
N = int(ip[0])
T = int(ip[1])

result = []
nums = []
visited = []
for i in range(0, 8):
    visited.append(False)


def f(k, restr):

    if (k == T):
        print(restr)
        return

    for i in range(0, N):
        if (i != 0 and nums[i] == nums[i - 1] and not visited[i - 1]):
            continue
        if (not visited[i]):
            visited[i] = True
            f(k + 1, restr + (str(nums[i]) + ' '))
            visited[i] = False

    return


nums = input().split()
nums = list(map(int, nums))
nums.sort()

f(0, "")
