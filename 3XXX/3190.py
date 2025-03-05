def solve():
    import sys
    input = sys.stdin.readline
    from collections import deque
    import time

    N = int(input().strip())
    K = int(input().strip())

    board = [[0] * N for _ in range(N)]

    for i in range(K):
        row, col = map(int, input().split())
        board[row-1][col-1] = 1
    
    L = int(input().strip())

    command = deque()
    for i in range(L):
        second, direction = input().split()
        second = int(second)
        command.append((second,direction))

    snake = deque()
    snake.append([0,0]) # y, x
    board[0][0] = 2

    isVert = True
    isInc = True

    def move(isVertically, isIncreasing):
        if isVertically and isIncreasing:
            y = snake[0][0]
            x = snake[0][1] + 1
        elif not isVertically and isIncreasing:
            y = snake[0][0] + 1
            x = snake[0][1]
        elif isVertically and not isIncreasing:
            y = snake[0][0]
            x = snake[0][1] - 1
        elif not isVertically and not isIncreasing:
            y = snake[0][0] - 1
            x = snake[0][1]

        if x >= N or x < 0 or y >= N or y < 0:
            return 0
        
        if board[y][x] == 2:
            return 0
        
        snake.appendleft([y,x])

        if board[y][x] == 1:
            board[y][x] = 2
            
        elif board[y][x] == 0:
            board[y][x] = 2
            tail_y, tail_x = snake.pop()
            board[tail_y][tail_x] = 0

        return 1

    count = 0
    while count <= 10000:
        dir = ""

        if command and count >= command[0][0]:
            sec, dir = command.popleft()
        
        if isVert and isInc:
            if dir == "L":
                isVert = not isVert
                isInc = not isInc
            elif dir == "D":
                isVert = not isVert
        elif not isVert and isInc:
            if dir == "L":
                isVert = not isVert
            elif dir == "D":
                isVert = not isVert
                isInc = not isInc
        elif isVert and not isInc:
            if dir == "L":
                isVert = not isVert
                isInc = not isInc
            elif dir == "D":
                isVert = not isVert
        elif not isVert and not isInc:
            if dir == "L":
                isVert = not isVert
            elif dir == "D":
                isVert = not isVert
                isInc = not isInc

        result = move(isVert, isInc)
        count += 1
        # for row in board:
        #         print(" ".join(map(str, row)))
        # print()
        #time.sleep(1)
        if result == 0:
            break

    print(count)

if __name__ == "__main__":
    solve()