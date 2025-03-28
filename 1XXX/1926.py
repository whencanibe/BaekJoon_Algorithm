import sys
readline = sys.stdin.readline
from collections import deque

N, M = map(int, readline().split())

drawings = [list(map(int, readline().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

# 값이 1 인 위치가 입력으로 주어질 예정
def bfs(x , y):
    q = deque()
    visited[y][x] = True
    q.append((x,y))
    width = 1

    while q:
        tx , ty = q.popleft()
        for i in range(4):
            nx = tx + dx[i]
            ny = ty + dy[i]
            if 0 <= nx < M and 0 <= ny < N and not visited[ny][nx] and drawings[ny][nx] == 1:
                visited[ny][nx] = True
                width += 1
                q.append((nx,ny))
                drawings[ny][nx] = 2
    return width

results = [0]
drawing_count = 0
for i in range(N):
    for j in range(M):
        if not visited[i][j] and drawings[i][j] == 1:
            results.append(bfs(j,i))
            drawing_count += 1
print(drawing_count)
print(max(results))

# print(results)
# for row in drawings:
#     print(*row)