import sys
readline = sys.stdin.readline
    
def solve():
    T = int(readline().strip())

    stickers = []

    for _ in range(T):
        N = int(readline().strip())
        stickers = [list(map(int , readline().split())) for _ in range(2)]

        dp = [[0,0,0] for _ in range(N)]
        dp[0][0] = 0
        dp[0][1] = stickers[0][0]
        dp[0][2] = stickers[1][0]

        for i in range(1, N):
            dp[i][0] = max(dp[i-1][1], dp[i-1][2])
            dp[i][1] = max(dp[i-1][0] + stickers[0][i], dp[i-1][2] + stickers[0][i])
            dp[i][2] = max(dp[i-1][0] + stickers[1][i], dp[i-1][1] + stickers[1][i])
        
        print(max(dp[N-1][0],dp[N-1][1],dp[N-1][2]))

if __name__ == "__main__":
    solve()