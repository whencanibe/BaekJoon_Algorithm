//https://www.acmicpc.net/problem/9095
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    int num;
    std::cin >> N;
    for (int i = 0 ; i < N ; i++){
        std::cin >> num;
        std::vector<int> dp(num+1,0);
        dp[0] = 1;
        if (num >= 1) dp[1] = 1;
        if (num >= 2) dp[2] = 2;
        if (num >= 3) dp[3] = 4;

        //이번 j 순서때 1,2,3 중 하나를 더하게 될텐데 각 경우에서 그 전까지 수를 만들기 위해 구해진 경우의 수를 불러와야하는 것임.
        for (int j = 4 ; j <= num ; j++){
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        std::cout << dp[num] << std::endl;
    }
    return 0;
}
