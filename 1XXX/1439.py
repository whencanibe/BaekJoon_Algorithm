import sys
readline = sys.stdin.readline

def solve():
    S = list(map(int, readline().strip()))

    length = len(S)
    num_of_ones = 0
    num_of_zeros = 0

    if S[0] == 1:
        num_of_ones += 1
    elif S[0] == 0:
        num_of_zeros += 1
    
    for i in range(1, length):
        if S[i] != S[i-1]:
            if S[i] == 1:
                num_of_ones += 1
            elif S[i] == 0:
                num_of_zeros += 1
            
    result = min(num_of_ones, num_of_zeros)
    print(result)
    #print("one",num_of_ones,"zero",num_of_zeros)
if __name__ == "__main__":
    solve()