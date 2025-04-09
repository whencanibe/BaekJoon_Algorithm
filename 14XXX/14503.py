import sys
readline = sys.stdin.readline

def solve():
    N, M = map(int, readline().split())
    r, c, d = map(int, readline().split())
    
    room = [list(map(int, readline().split())) for _ in range(N)]
    cleaned = [[False]*M for _ in range(N)]
    
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    cleaned[r][c] = True
    count = 1
    
    while True:
        check_cleaned = False
        for _ in range(4):
            d = (d - 1) % 4        # 왼쪽으로 회전
            dr, dc = directions[d]
            nr, nc = r + dr, c + dc
            
            # 청소 가능한 칸이면 전진 후 청소
            if 0 <= nr < N and 0 <= nc < M:
                if room[nr][nc] == 0 and not cleaned[nr][nc]:
                    r, c = nr, nc
                    cleaned[r][c] = True
                    count += 1
                    check_cleaned = True
                    break
        
        # 네 방향 다 확인해도 청소할 칸을 못 찾았다면,
        # 바라보는 방향 그대로 뒤로 이동 가능한지 확인
        if not check_cleaned:
            back_d = (d + 2) % 4
            br, bc = directions[back_d]
            nr, nc = r + br, c + bc

            # 뒤쪽 칸이 벽이 아니면 후진
            if 0 <= nr < N and 0 <= nc < M and room[nr][nc] == 0:
                r, c = nr, nc
            else:
                # 후진도 못 하면 작동 멈춤
                break
    
    print(count)

if __name__ == "__main__":
    solve()
