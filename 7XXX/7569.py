def solve():
    import sys
    from collections import deque

    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline

    M, N ,H = map(int, input().split())

    box = []
    queue = deque()
    visited = [[[False] * M for _ in range(N)] for _ in range(H)]

    for h in range(H):
        layer = []
        for i in range(N):
            row = list(map(int, input().split()))
            layer.append(row)

            for index, value in enumerate(row):
                if value == 1:
                    queue.append((h,i,index))
                    visited[h][i][index] = True
            
        box.append(layer)
    
    dz = [0,0,0,0,-1,1]
    dy = [1,-1,0,0,0,0]
    dx = [0,0,-1,1,0,0]

    

    while queue:
        z,y,x = queue.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            if 0<= nx < M and 0 <= ny < N and 0 <= nz < H:
                if box[nz][ny][nx] == 0:
                    queue.append((nz,ny,nx))
                    box[nz][ny][nx] = box[z][y][x] + 1

    result = 0
    for h in range(H):
        for i in range(N):
            for j in range(M):
                if box[h][i][j] == 0:
                    print(-1)
                    sys.exit(0)
                result = max(result, box[h][i][j])
    
    print(result - 1)

if __name__ == "__main__":
    solve()