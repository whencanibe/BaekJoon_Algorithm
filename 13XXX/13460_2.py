from collections import deque
import sys
import time
def solve():
    input = sys.stdin.readline

    N, M = map(int, input().split())
    board = [list(input().strip()) for _ in range(N)]

    rx = ry = bx = by = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 'R':
                rx, ry = j, i
            elif board[i][j] == 'B':
                bx, by = j, i

    directions = [(-1,0),(1,0),(0,1),(0,-1)]

    def move(ball_x, ball_y, dx, dy):
        
        count = 0
        while board[ball_y + dy ][ball_x + dx] != '#' and board[ball_y][ball_x] != 'O':
            ball_x += dx
            ball_y += dy
            count += 1
            if board[ball_y][ball_x] == 'O':
                break
        
        return ball_x,ball_y,count

    def bfs(srx,sry,sbx,sby):
        queue = deque()
        queue.append((srx,sry,sbx,sby,0))
        visited = {(srx,sry,sbx,sby)}

        while queue:
            red_x, red_y, blue_x, blue_y, moves = queue.popleft()

            if moves >= 10:
                return -1

            for dx, dy in directions:
                nrx, nry , r_count = move(red_x, red_y, dx, dy)
                nbx, nby , b_count = move(blue_x, blue_y, dx, dy)

                if board[nby][nbx] == 'O':
                    continue

                if board[nry][nrx] == 'O':
                    return moves + 1
                
                if nrx == nbx and nry == nby:
                    if r_count > b_count:
                        nrx -= dx
                        nry -= dy
                    else:
                        nbx -= dx
                        nby -= dy
                
                if (nrx, nry, nbx, nby) not in visited:
                    visited.add((nrx, nry, nbx, nby))
                    queue.append((nrx,nry, nbx, nby, moves + 1))

                    # board[nry][nrx] = 'R'
                    # for row in board:
                    #     print("".join(map(str, row)))
                    # print()
                    # time.sleep(2)

        return -1

    result = bfs(rx, ry, bx, by)
    print(result)
                

if __name__ == "__main__":
    solve()