import sys
readline = sys.stdin.readline

N = int(readline().strip())
M = int(readline().strip())

adj = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for i in range(M):
    A, B = map(int, readline().split())
    adj[A].append(B)
    adj[B].append(A)

def dfs(start):
    visited[start] = True
    for neighbor in adj[start]:
        if not visited[neighbor]:
            dfs(neighbor)

dfs(1)
count = 0
for v in visited:
    if v == True:
        count += 1
print(count - 1)
