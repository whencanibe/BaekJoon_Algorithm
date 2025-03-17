import sys
readline = sys.stdin.readline

def solve():
    N = int(readline().strip())

    dp = [0] * (N + 1)
    dp[1] = 1

    if N > 1:
        dp[2] = 2
        for i in range(3, N+1):
            dp[i] = (dp[i - 1] + dp[i-2]) % 15746

    print(dp[N])

if __name__ == "__main__":
    solve()