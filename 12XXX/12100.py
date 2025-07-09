import sys
import copy
from collections import deque

readline = sys.stdin.readline

def erase(board, i, j):
    board[i][j] = 0

def appendDeque(dq,board,i,j):
    dq.append(board[i][j])
    erase(board, i, j)

# 1. 뒤에 넣고
# 2. 숫자 같으면 꺼내서 더한 다음 지금까지 덱에있던 것 다 저장함
# 3. 그다음 쭉 진행하고 덱에 남은거도 빼서 저장
def move_left(board):
    N = len(board)
    for i in range(N):
        dq = deque()
        idx = 0
        for j in range(N):
            if board[i][j] == 0:
                continue

            if dq:
                last = dq.pop()
                if last == board[i][j]:
                    last += board[i][j]
                    while dq:
                        board[i][idx] = dq.popleft()
                        idx += 1
                    board[i][idx] = last
                    erase(board, i, j)
                    idx += 1

                else:
                    dq.append(last)
                    appendDeque(dq, board, i, j)
            else:
                appendDeque(dq, board, i, j)

        while dq:
            board[i][idx] = dq.popleft()
            idx += 1

def rotate_clockwise(board):
    new_board = copy.deepcopy(board)
    size = len(board)
    for i in range(size):
        for j in range(size):
            new_board[j][size-1-i] = board[i][j]
    
    return new_board

def print_board(board,n):
    print("b",n)
    for row in board:
        print(*row)
        
def get_options(board):
    rotate_options = []
    for i in range(4):
        rotate_options.append(rotate_clockwise(board))
    return rotate_options

def solve():
    N = int(readline().strip())
    board = [list(map(int, readline().split())) for _ in range(N)]

    max_num = 0
    b1 = copy.deepcopy(board)
    #print_board(b1,1)
    for i in range(4):
        b1 = rotate_clockwise(b1)
        b2 = copy.deepcopy(b1)
        move_left(b2)
        #print_board(b2,2)
        for j in range(4):
            b2 = rotate_clockwise(b2)
            b3 = copy.deepcopy(b2)
            move_left(b3)
            #print_board(b3,3)
            for k in range(4):
                b3 = rotate_clockwise(b3)
                b4 = copy.deepcopy(b3)
                move_left(b4)
                #print_board(b4,4)
                
                for l in range(4):
                    b4 = rotate_clockwise(b4)
                    b5 = copy.deepcopy(b4)
                    move_left(b5)
                    #print_board(b5,5)
                    for m in range(4):
                        b5 = rotate_clockwise(b5)
                        b6 = copy.deepcopy(b5)
                        move_left(b6)
                        #print_board(b6,6)
                        tmp = max([item for row in b6 for item in row])
                        #print("i", i, tmp)  
                        if tmp > max_num:
                            max_num = tmp
    print(max_num)
            
                    

if __name__ == "__main__":
    solve()
