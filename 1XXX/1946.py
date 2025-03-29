import sys
readline = sys.stdin.readline

T = int(readline().strip())


for _ in range(T):
    N  = int(readline().strip())
    candidates = [list(map(int, readline().split())) for _ in range(N)]
    candidates.sort(key=lambda x: x[0])

    count = 1
    best_interview = candidates[0][1]
    for i in range(1, N):
        if candidates[i][1] < best_interview:
            count += 1
            best_interview = candidates[i][1]

    print(count)