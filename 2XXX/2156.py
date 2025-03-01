def solve():
    import sys
    input = sys.stdin.readline
    N = int(input().strip())

    wine = [0] * (N+1)
    for i in range(1, N+1):
        wine[i] = int(input().strip())
    
    dp = [0] * (N + 1)
    dp[1] = wine[1]

    if N >= 2:
        dp[2] = wine[1] + wine[2]
    
    #N < 3 이면 어차피 실행 안됨
    for i in range(3,N + 1):
        dp[i] = max(dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i])
    
    print(dp[N])
    

if __name__ == "__main__":
    solve()