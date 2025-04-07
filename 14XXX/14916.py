N = int(input())

coin = 0
while N > 0:
    if N % 5 == 0:
        coin += N // 5
        N %= 5
        break
    
    N -= 2
    coin += 1

if N < 0:
    print(-1)
else:
    print(coin)