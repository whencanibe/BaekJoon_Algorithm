import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline

dx = [1,-1,0,0]
dy = [0,0,1,-1]
    
T = int(readline().strip())

for _ in range(T):
    M, N, K = map(int, readline().split())
    farm = [[0] * M for _ in range(N)]
    visited = [[False] * M for _ in range(N)]

    def dfs(y, x):
        visited[y][x] = True
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0<= nx < M and 0 <= ny < N:
                if not visited[ny][nx] and farm[ny][nx] == 1:
                    dfs(ny, nx)

    for _ in range(K):
        x, y = map(int, readline().split())
        farm[y][x] = 1

    count = 0
    for i in range(N):
        for j in range(M):
            if farm[i][j] == 1 and not visited[i][j]:
                dfs(i, j)
                count += 1
    print(count)
        