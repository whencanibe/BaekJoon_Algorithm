import sys
from collections import deque

readline = sys.stdin.readline

def solve():
    N, M = map(int, readline().split())
    numbers = list(map(int, readline().split()))

    dq = deque(range(1, N+1))

    total = 0

    for num in numbers:
        idx = dq.index(num)
        length = len(dq)
        left = idx
        right = length - idx

        if left <= right:
            dq.rotate(-left)
            total += left
        else:
            dq.rotate(right)
            total += right
        
        dq.popleft()
    
    print(total)

    

if __name__ == "__main__":
    solve()