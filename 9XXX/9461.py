def solve():
    import sys
    input = sys.stdin.readline

    T = int(input().strip())

    dp = [0] * (101)

    dp[1]= dp[2] = dp[3] = 1

    for i in range(4 ,101):
        dp[i] = dp[i - 2] + dp[i - 3]


    for _ in range(T):
        N = int(input().strip())
        print(dp[N])




if __name__ == "__main__":
    solve()