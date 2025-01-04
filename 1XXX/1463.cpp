//https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;

    std::vector<int> dp(N+1,0);
    for (int i = 2 ; i <= N ; i++){
        dp[i] = dp[i-1]+1;
        if (i % 2 == 0) dp[i] = std::min(dp[i],dp[i/2]+1);
        if (i % 3 == 0) dp[i] = std::min(dp[i],dp[i/3]+1);
    }

    std::cout << dp[N] << std::endl;
    return 0;
}
