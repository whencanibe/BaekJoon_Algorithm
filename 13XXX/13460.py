from collections import deque
import sys

def solve():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    board = [list(input().strip()) for _ in range(N)]
    
    rx = ry = bx = by = 0
    # 구슬과 구멍의 초기 위치 찾기
    for i in range(N):
        for j in range(M):
            if board[i][j] == 'R':
                rx, ry = i, j
            elif board[i][j] == 'B':
                bx, by = i, j

    # 상, 하, 좌, 우 방향 벡터
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # 구슬을 한 방향으로 기울였을 때 이동시키는 함수
    def move(x, y, dx, dy):
        count = 0  # 해당 방향으로 이동한 칸의 수
        # 벽(#)에 닿거나 구멍(O)에 빠질 때까지 이동
        while board[x + dx][y + dy] != '#' and board[x][y] != 'O':
            x += dx
            y += dy
            count += 1
            if board[x][y] == 'O':
                break
        return x, y, count

    # 상태: (빨간 구슬 x, 빨간 구슬 y, 파란 구슬 x, 파란 구슬 y, 이동 횟수)
    queue = deque()
    queue.append((rx, ry, bx, by, 0))
    visited = set()
    visited.add((rx, ry, bx, by))
    
    while queue:
        rx, ry, bx, by, moves = queue.popleft()
        if moves >= 10:  # 10번 이하의 기울임으로 해결해야 함
            break
        
        for dx, dy in directions:
            nrx, nry, r_count = move(rx, ry, dx, dy)
            nbx, nby, b_count = move(bx, by, dx, dy)
            
            # 파란 구슬이 구멍에 빠지면 실패이므로 이 방향은 무시
            if board[nbx][nby] == 'O':
                continue
            
            # 빨간 구슬이 구멍에 빠졌다면 성공!
            if board[nrx][nry] == 'O':
                print(moves + 1)
                return
            
            # 만약 두 구슬이 같은 칸에 있다면, 이동 거리가 더 긴 구슬이 한 칸 뒤로 이동
            if nrx == nbx and nry == nby:
                if r_count > b_count:
                    nrx -= dx
                    nry -= dy
                else:
                    nbx -= dx
                    nby -= dy
            
            if (nrx, nry, nbx, nby) not in visited:
                visited.add((nrx, nry, nbx, nby))
                queue.append((nrx, nry, nbx, nby, moves + 1))
    
    print(-1)

if __name__ == '__main__':
    solve()
