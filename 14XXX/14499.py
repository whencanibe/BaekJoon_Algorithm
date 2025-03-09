import sys
readline = sys.stdin.readline

# (x, y) or (y,x) 문제의 순서와 내 코드의 순서가 일치하는 지 확인!!
def solve():
    N, M, y, x, K = map(int, readline().split())
    board = [list(map(int, readline().split())) for _ in range(N)]
    command = list(map(int , readline().split()))

    dx = [0,1,-1,0,0] # 1-based index
    dy = [0,0,0,-1,1]
    
    dice = [0,0,0,0,0,0] # top, bottom , left , right , front, back

    def roll_dice(dice, direction):
        top, bottom , left , right , front, back = dice
        if direction == 1:
            return [left , right , bottom, top ,front,back]
        elif direction == 2:
            return [right , left , top, bottom ,front,back]
        elif direction == 3:
            return [front, back ,left, right, bottom, top]
        elif direction == 4:
            return [back, front ,left, right, top, bottom]
    
    for dir in command:
        nx = x + dx[dir]
        ny = y + dy[dir]

        if 0 <= nx < M and 0 <= ny < N:
            dice = roll_dice(dice, dir)
            if(board[ny][nx] == 0):
                board[ny][nx] = dice[1] #bottom
            else:
                dice[1] = board[ny][nx]
                board[ny][nx] = 0
            x = nx
            y = ny
            print(dice[0])



if __name__ == "__main__":
    solve()