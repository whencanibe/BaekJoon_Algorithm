//https://www.acmicpc.net/problem/11726
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int mod = 10007;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n ; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % mod; // mod연산 전체에 해줘야함 
        //or
        //dp[i] = (dp[i-2] % mod + dp[i-1] % mod) % mod;
    }
    cout << dp[n];
    return 0;
}

