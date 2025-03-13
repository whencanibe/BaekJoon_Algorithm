import sys
readline = sys.stdin.readline

def solve():
    A, B = map(int, readline().split())
    count = 0

    while B > A:
        if B % 10 == 1:
            B -= 1
            B = B // 10
            count += 1
        elif B % 2 == 0:
            B = B // 2
            count += 1
        else:
            break
    
    if A == B:
        print(count + 1)
    else:
        print(-1)

if __name__ == "__main__":
    solve()