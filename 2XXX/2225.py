def solve():
    import sys
    input = sys.stdin.readline

    N , K = map(int , input().split())

    # dp[i][j] : i개로 int j 만들기
    dp = [[0] * (N + 1) for _ in range(K + 1)]

    for k in range(1 , K+1):
        dp[k][0] = 1

    # DP 테이블 채우기
    for k in range(1, K + 1):  # 1개부터 K개까지 숫자를 사용할 때
        for n in range(1, N + 1): 
            dp[k][n] = (dp[k][n-1] + dp[k-1][n]) % 1000000000 


    result = dp[K][N]
    print(result)

if __name__ == "__main__":
    solve()