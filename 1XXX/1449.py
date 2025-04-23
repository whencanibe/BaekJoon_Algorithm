import sys
readline = sys.stdin.readline

N, L = map(int , readline().split())

holes = list(map(int, readline().split()))
holes.sort()

blocked = [False] * N

count = 0
for i in range(N):
    if blocked[i] == False:
        blocked[i] = True
        for j in range(i+1, N):
            if not blocked[j] and holes[j] - holes[i] <= L - 1:
                blocked[j] = True
        count += 1

print(count)

