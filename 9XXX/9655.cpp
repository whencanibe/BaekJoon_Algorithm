#include <iostream>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    int *dp = new int[N + 1];

    // 1: SK 0: CY
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;

    for (int i = 4 ; i < N + 1 ; i++){
        if(dp[i-1] == 0 || dp[i-3] == 0){
            dp[i] = 1;
        } else{
            dp[i] = 0;
        }
    }

    if(dp[N] == 1) std::cout << "SK" << std::endl;
    else std::cout << "CY" << std::endl;
    delete[] dp;
    return 0;
}
