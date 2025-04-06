def solve():
    T = int(input())
    if T % 10 != 0:
        print(-1)
        return
    
    A,B,C = 0,0,0
    
    while T > 0:
        if T >= 300:
            A += T // 300
            T %= 300
            continue
        
        if T >= 60:
            B += T // 60
            T %= 60
            continue
        
        C += T // 10
        T %= 10
    
    print(A,B,C)
        
        
    

solve()
