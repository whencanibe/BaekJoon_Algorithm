import sys
from collections import deque
readline = sys.stdin.readline

T = int(readline().strip())

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

def bfs(visited, board, x, y, I):

    q = deque()
    count = 0
    q.append((x,y,count))
    visited[y][x] = True
    while q:
        cx, cy, cur_count = q.popleft()
        for i in range(8):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < I and 0 <= ny < I and not visited[ny][nx]:
                visited[ny][nx] = True
                q.append((nx, ny, cur_count + 1))
                if board[ny][nx] == 2:
                    return cur_count + 1
                
    return -1 # -1 이면 잘못된것

for _ in range(T):
    I = int(readline().strip())
    board = [[0] * I for _ in range(I)]
    visited = [[False] * I for _ in range(I)]

    knight_x, knight_y = map(int, readline().split())
    goal_x, goal_y = map(int, readline().split())

    if knight_x == goal_x and knight_y == goal_y:
        print(0)
        continue

    board[knight_y][knight_x] = 1
    board[goal_y][goal_x] = 2

    result = bfs(visited, board, knight_x, knight_y, I)

    print(result)
