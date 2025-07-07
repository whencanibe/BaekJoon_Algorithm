def solve():
    N = int(input())

    if N <= 1:
        print(1)
        return
    
    dp = [0] * (N + 1)

    dp[1] = 1
    dp[2] = 2

    for n in range(3,N+1):
        dp[n] = (dp[n-2] + dp[n-1]) % 10007

    print(dp[N])

solve()