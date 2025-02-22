def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())

    # 1일부터 N일까지의 상담 정보를 저장하기 위한 리스트
    T = [0] * (N + 1)
    P = [0] * (N + 1)
    
    for i in range(1, N + 1):
        t, p = map(int, input().split())
        T[i] = t
        P[i] = p
    
    dp = [0] * (N + 2)

    for i in range(N,0,-1):
        if i + T[i] <= N + 1:
            dp[i] = max(dp[i+1], P[i] + dp[i + T[i]])
        else:
            dp[i] = dp[i+1]

    print(dp[1])

if __name__ == "__main__":
    solve()