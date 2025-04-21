# line == 0 and count != 0 이면 자신보다 큰 애들이 들어올 자리이고 line != 0이면 이미 자기보다 작은 애들 들어와 있는것
# 따라서 line == 0 and count == 0 일 때 count -= 1 해서 자신 자리 찾기
N = int(input())
info = list(map(int, input().split()))

line = [0] * N  
for height in range(1, N + 1):
    count = info[height - 1] 
    pos = 0
    for i in range(N):
        if line[i] == 0:
            if count == 0:
                line[i] = height
                break
            count -= 1

print(' '.join(map(str, line)))
