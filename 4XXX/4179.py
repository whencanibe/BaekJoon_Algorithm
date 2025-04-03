import sys
from collections import deque
readline = sys.stdin.readline

R, C = map(int ,readline().split())

maze = [list(readline().strip()) for _ in range(R)]

jihun = [0,0]
j_visited = [[False] * C for _ in range(R)]

fire = []
fire_visited = [[False] * C for _ in range(R)]
fire_time = [[-1] * C for _ in range(R)]
for i in range(R):
    for j in range(C):
        if maze[i][j] == 'J':
            jihun = [j, i]
            j_visited[i][j] = True
        elif maze[i][j] == 'F':
            fire.append([j, i])
            fire_visited[i][j] = True
        elif maze[i][j] == '#':
            fire_visited[i][j] = True

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def set_fire_time():
    count = 0
    fire_q = deque()
    for f in fire:
        fire_q.append((f[0], f[1], count))

    while fire_q:
        fire_cx, fire_cy, cur_count = fire_q.popleft()

        for i in range(4):
            fire_nx = fire_cx + dx[i]
            fire_ny = fire_cy + dy[i]
            if 0 <= fire_nx < C and 0 <= fire_ny < R and maze[fire_ny][fire_nx] != '#' and not fire_visited[fire_ny][fire_nx]:
                fire_q.append((fire_nx,fire_ny, cur_count + 1))
                fire_time[fire_ny][fire_nx] = cur_count + 1
                fire_visited[fire_ny][fire_nx] = True

def bfs():
    count = 0
    jq = deque()
    jq.append((jihun[0], jihun[1], count))

    while jq:
        j_cx, j_cy, cur_count = jq.popleft()
        if j_cx == C - 1 or j_cy == R - 1 or j_cx == 0 or j_cy == 0:
            return cur_count + 1

        for i in range(4):
            j_nx = j_cx + dx[i]
            j_ny = j_cy + dy[i]
            if 0 <= j_nx < C and 0 <= j_ny < R and maze[j_ny][j_nx] == '.' and(fire_time[j_ny][j_nx] == -1 or cur_count + 1 < fire_time[j_ny][j_nx])  and not j_visited[j_ny][j_nx]:
                j_visited[j_ny][j_nx] = True
                jq.append((j_nx, j_ny, cur_count + 1))

    return -1

set_fire_time()

result = bfs()
if result == -1:
    print("IMPOSSIBLE")
else:
    print(result)
