import sys
def solve():
    N = int(input())
    result = 0
    while N >= 0: # 0이 되면 if 문에도 걸려 출력됨
        if N % 5 == 0:
            result += N // 5
            print(result)
            return
        
        N -= 3
        result += 1
    
    print(-1)

if __name__ == "__main__":
    solve()