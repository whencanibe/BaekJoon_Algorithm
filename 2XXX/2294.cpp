#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(k + 1, INT_MAX); // 동전의 최소 갯수
    dp[0] = 0;
    for (int coin : coins)
    {
        for (int i = coin; i <= k; i++)
        {
            if (dp[i - coin] != INT_MAX) // Overflow방지
            { 
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
            // for (int i = 0 ; i <= k ; i++){
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
        }
    }
    if (dp[k] == INT_MAX)
        cout << -1;
    else
        cout << dp[k] << endl;

    return 0;
}