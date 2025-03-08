def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())
    nums = list(map(int, input().split()))
    dp = [0] * N
    dp[0] = nums[0]

    for i in range(1,N):
        dp[i] = max(nums[i] , dp[i-1] + nums[i])
    
    max2 = max(dp)
    print(max2)

if __name__ == "__main__":
    solve()