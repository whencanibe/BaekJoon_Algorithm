#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    int* A = new int[N];
    int* dp = new int[N];

    for (int i = 0 ; i < N; i++){
        std::cin >> A[i];
        dp[i] = 1;
    }

    for (int i = 1 ; i < N ; i++){
        for (int j = 0 ; j < i ; j++){
            if(A[j] > A[i]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    int result = dp[0];
    for (int i = 1 ; i < N ; i++){
        result = std::max(result, dp[i]);
    }

    std::cout << result << std::endl;

    delete[] dp;
    delete[] A;
    return 0;
}
