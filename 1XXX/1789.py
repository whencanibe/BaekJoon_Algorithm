def solve():
    import sys
    input = sys.stdin.readline

    S = int(input().strip())

    i = 1
    count = 0
    while S > 0:
        if S < i:
            break
        S -= i
        i += 1
        count += 1
    
    print(count)

        

if __name__ == "__main__" :
    solve()