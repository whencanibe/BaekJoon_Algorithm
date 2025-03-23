import sys
from collections import deque
readline = sys.stdin.readline
N, M, V = map(int, readline().split())

graph = [[] for _ in range(N + 1)]

for i in range(M):
    a, b = map(int , readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    graph[i].sort()

visited = [False] * (N + 1)

def bfs():
    q = deque()
    result = []
    q.append(V)
    #visited[V] = True
    while q:
        v = q.popleft()
        result.append(v)
        visited[v] = True
        for next in graph[v]:
            if not visited[next]:
                q.append(next)
                visited[next] = True
                
    print(" ".join(map(str, result)))

dfs_result = []
def dfs(start):
    q = deque()
    
    q.append(start)
    visited[start] = True
    dfs_result.append(start)

    for neighbor in graph[start]:
        if not visited[neighbor]:
            dfs(neighbor)
            
dfs(V)
print(" ".join(map(str, dfs_result)))

visited = [False] * (N + 1)
bfs()
