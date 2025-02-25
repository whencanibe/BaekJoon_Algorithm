def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())

    # n이 1인 경우 바로 출력
    if N == 1:
        print(1)
        return
    dp = [0] * (N + 1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 3

    for i in range(3, N+1):
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007

    print(dp[N])


if __name__ == "__main__":
    solve()