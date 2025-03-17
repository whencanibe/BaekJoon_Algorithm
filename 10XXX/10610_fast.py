def solve():
    N = input().strip()
    
    digits = list(N)
    
    if '0' not in digits:
        print(-1)
        return
    
    total_sum = sum(map(int, digits))
    if total_sum % 3 != 0:
        print(-1)
        return
    
    digits.sort(reverse=True)
    print("".join(digits))


solve()
