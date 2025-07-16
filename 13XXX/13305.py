import sys

readline = sys.stdin.readline

N = int(readline().strip())

road = list(map(int, readline().split()))
prices = list(map(int, readline().split()))

total = 0
idx = 0
tmp = -1

while idx <= N - 2:
    if tmp >= idx:
        idx += 1
        continue

    total += road[idx] * prices[idx]
    for i in range(idx + 1, N - 1):
        if prices[idx] < prices[i]:
            # print("idx", idx, "i", i)
            total += prices[idx] * road[i]
            tmp = i
        else:
            break
    idx += 1
print(total)
