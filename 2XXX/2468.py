def solve():
    import sys
    from collections import deque

    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)

    N = int(input().strip())

    grid = []
    max_height = 0
    for i in range(N):
        row = list(map(int, input().split()))
        tmp = max(row)
        max_height = max(max_height, tmp)
        grid.append(row)
    
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]

    def bfs(x, y, visited):
        queue = deque()
        queue.append([x,y])

        while queue:
            cx, cy = queue.popleft()
            for i in range(4):
                nx = cx + dx[i]
                ny = cy + dy[i]
                if 0 <= nx < N and 0 <= ny < N and not visited[ny][nx]:
                    queue.append([nx, ny])
                    visited[ny][nx] = True

    
    max_nums = []

    for k in range(0 , max_height + 1):
        visited = [[False] * N for _ in range(N)]
        safe_spots = []

        for i in range(N):
            for j in range(N):
                if grid[i][j] <= k:
                    visited[i][j] = True
                else:
                    safe_spots.append([i,j])
        
        count = 0
        for l in range(len(safe_spots)):
            x = safe_spots[l][1]
            y = safe_spots[l][0]

            if not visited[y][x]:
                bfs(x,y,visited)
                count += 1

        max_nums.append(count)

    print(max(max_nums))           
if __name__ == "__main__":
    solve()