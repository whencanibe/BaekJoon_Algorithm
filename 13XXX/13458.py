import sys
readline = sys.stdin.readline

def solve():
    N = int(readline().strip())
    num_of_people = list(map(int, readline().split()))
    B, C = map(int, readline().split())

    count = 0
    for i in range(N):
        num_of_people[i] -= B
        count += 1
        if num_of_people[i] > 0:
            count += num_of_people[i] // C
            num_of_people[i] %= C
        if num_of_people[i] > 0:
            count += 1
            

    print(count)
if __name__ == "__main__":
    solve()