import sys
readline = sys.stdin.readline

N = int(readline().strip())

INF = float('inf')

houses = [list(map(int, readline().split())) for _ in range(N)]
ans = INF

for first_color in range(3):
    dp = [[INF] * 3 for _ in range(N)]
    dp[0][first_color] = houses[0][first_color]

    for i in range(1, N):
        dp[i][0] = houses[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = houses[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = houses[i][2] + min(dp[i-1][0], dp[i-1][1])

    for last_color in range(3):
        if last_color == first_color:
            continue
        ans = min(ans, dp[N-1][last_color])

print(ans)