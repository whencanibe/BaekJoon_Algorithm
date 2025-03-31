import sys
from collections import deque

readline = sys.stdin.readline

N = int(readline().strip())
A, B = map(int, readline().split())
M = int(readline().strip())

relations = [[] for _ in range(N+1)]

for i in range(M):
    parent, child = map(int, readline().split())
    relations[parent].append(child)
    relations[child].append(parent)

def bfs():
    q = deque()
    count = 0

    q.append((A, count))
    visited = [False] * (N + 1)
    visited[A] = True
    
    while q:
        node, cur_count = q.popleft()
        for neighbor in relations[node]:
            if neighbor == B:
                return cur_count + 1
            
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append((neighbor, cur_count + 1))
    
    return -1

print(bfs())



