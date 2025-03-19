import sys
readline = sys.stdin.readline

def solve():
    N = int(readline().strip())
    prices = list(map(int, readline().split()))
    prices.insert(0, 0)

    dp = [0] * (N + 1)
    dp[1] = prices[1]

    for i in range(2, N+1):
        for j in range(1, i):
            dp[i] = max(dp[i], dp[i-j] + dp[j], prices[i])
    
    #print(dp)
    print(dp[N])

if __name__ == "__main__":
    solve()