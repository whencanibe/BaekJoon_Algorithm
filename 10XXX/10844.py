def solve():
    import sys
    input = sys.stdin.readline
    N = int(input().strip())
    MOD = 1000000000

    # dp[i][j] : i 자리에서 j로 끝나는 수
    dp = [[0] * 10 for _ in range(N + 1)]

    for i in range(1, 10):
        dp[1][i] = 1

    for i in range(2, N + 1):
        for j in range(10):
            if 0 < j < 9:
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
            elif j == 0:
                dp[i][j] = dp[i-1][j+1]
            elif j == 9:
                dp[i][j] = dp[i-1][j-1]
    
    result = sum(dp[N]) % MOD
    print(result)

    

if __name__ == "__main__":
    solve()