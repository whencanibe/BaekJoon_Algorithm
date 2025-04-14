#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int *A = new int[N];
    int *dp = new int[N];
    
    for (int i = 0 ; i <  N; i++){
        cin >> A[i];
        dp[i] = A[i];
    }

    for (int i = 1 ; i < N ; i++){
        for (int j = 0 ; j < i ; j++){
            if(A[i] > A[j]){
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }
    int result = dp[0];
    for (int i = 1 ; i <  N ; i++){
        if (result < dp[i]){
            result = dp[i];
        }
    }

    cout << result << endl; 

    delete[] dp;
    delete[] A;
    return 0;
}
