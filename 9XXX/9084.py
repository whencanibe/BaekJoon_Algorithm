import sys
readline = sys.stdin.readline

T = int(readline().strip())

for _ in range(T):
    N = int(readline().strip())
    coins = list(map(int, readline().split()))
    amount = int(readline().strip())

    dp = [0] * (amount + 1)
    dp[0] = 1

    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    
    print(dp[amount])