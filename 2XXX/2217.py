def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())

    ropes = []
    for i in range(N):
        ropes.append(int(input().strip()))

    ropes.sort()

    max_weight = []

    for i in range(N):
        max_weight.append(ropes[i] * (N - i))

    print(max(max_weight))

if __name__ == "__main__":
    solve()