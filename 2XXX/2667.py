import sys
readline = sys.stdin.readline

N = int(readline().strip())

maps = [list(map(int, readline().strip())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def dfs(y, x):
    visited[y][x] = True
    count = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<= nx < N and 0 <= ny < N and not visited[ny][nx] and maps[ny][nx] == 1:
            count += dfs(ny, nx)
    
    return count

results = []
count = 0

for i in range(N):
    for j in range(N):
        if maps[i][j] == 1 and not visited[i][j]:
            results.append(dfs(i, j))
            count += 1

results.sort()
print(count)
for i in results:
    print(i)
