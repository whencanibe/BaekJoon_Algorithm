def solve():
    import sys
    input = sys.stdin.readline

    grid = []
    N, M = map(int , input().strip())

    for i in range(N):
        row = list(map(int, input().split()))
        grid.append(row)

    dp = [[0] * (N + 1) for _ in range(N + 1)]

    for i in range(1 ,N+1):
        for j in range(1, N+1):
            dp[i][j] = dp[i][j-1] + grid[i][j]
            
    
    for j in range(M):
        x1,y1,x2,y2 = map(int, input().split())



if __name__ == "__main__":
    solve()