def solve():
    import sys
    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline

    N = int(input().strip())
    grid = [list(input().strip()) for _ in range(N)]

    visited = [[False] * N for _ in range(N)]

    def dfs(x,y,color,v,g):
        v[x][y] = True
        for dx, dy in [(-1,0),(1,0),(0,1),(0,-1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < N:
                if not v[nx][ny] and g[nx][ny] == color:
                    dfs(nx,ny,color,v,g)

    count = 0
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                dfs(i,j,grid[i][j],visited,grid)
                count += 1
    
    visited2 = [[False] * N for _ in range(N)]
    grid2 = [row[:] for row in grid]
    for i in range(N):
        for j in range(N):
            if grid2[i][j] == 'G':
                grid2[i][j] = 'R'
    
    count2 = 0
    for i in range(N):
        for j in range(N):
            if not visited2[i][j]:
                dfs(i,j,grid2[i][j],visited2,grid2)
                count2 += 1
    print(count, count2)

if __name__ == "__main__":
    solve()