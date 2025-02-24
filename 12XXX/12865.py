def solve():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())

    W = [0] * (N)
    V = [0] * (N)
    for i in range(N):
        weight, value = map(int, input().split())
        W[i] = weight
        V[i] = value

    dp = [0] * (K + 1)
    for i in range(N):
        for j in range(K,W[i] - 1,-1):
            dp[j] = max(dp[j], dp[j-W[i]] + V[i])

    print(dp[K])
    
if __name__ == "__main__":
    solve()