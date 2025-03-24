import sys
from collections import deque
readline = sys.stdin.readline

N, M = map(int, readline().split())

maze = [list(readline().strip()) for _ in range(N)]
visited = [[False] * M for _ in range(N)]


dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs():
    q = deque()
    q.append((0,0,1)) # y ,x, bfs 몇번째 과정 실행중인지 //  0 based
    visited[0][0] = True
    while q:
        y, x, c = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N and maze[ny][nx] == '1' and not visited[ny][nx]:
                visited[ny][nx] = True
                q.append((ny, nx, c + 1))
                
                if nx == M - 1 and ny == N - 1:
                    return c + 1


print(bfs())