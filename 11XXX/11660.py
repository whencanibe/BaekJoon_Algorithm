import sys
readline = sys.stdin.readline
def solve():    
    N, M = map(int , readline().split())

    grid = [list(map(int, readline().split())) for _ in range(N)]

    dp = [[0] * (N+1) for _ in range(N+1)] # 1-based 

    for i in range(1, N+1):
        for j in range(1 ,N+1):
            dp[i][j] = grid[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
    
    result = []
    for i in range(M):
        # x, y 행-열 문제 잘 읽기
        x1, y1, x2, y2 = map(int, readline().split())
        
        tmp = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
        result.append(tmp)
            
    for res in result:
        print(res)
            
    

if __name__ == "__main__":
    solve()