def solve():
    N = int(input().strip())

    dp = [0] * (N + 1)
    dp[1] = 1
    
    if N > 1:
        dp[2] = 1

    for i in range(3 , N + 1):
        dp[i] = dp[i-1] + dp[i-2]

    print(dp[N])

if __name__ == "__main__":
    solve()