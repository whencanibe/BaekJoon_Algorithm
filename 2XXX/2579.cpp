//https://www.acmicpc.net/problem/2579
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int *Stairs = new int[n+1];
    Stairs[0] = 0;
    for (int i = 1 ; i <= n ; i++){
        cin >> Stairs[i];
    }

    int *dp = new int[n+1];
    fill(dp,dp+n,0);
    
    dp[0] = 0;
    if (n >= 1)
        dp[1] = Stairs[1];
    if (n >= 2)
        dp[2] = dp[1] + Stairs[2];
    if (n >= 3)
        dp[3] = max(Stairs[1]+ Stairs[3], Stairs[2] + Stairs[3]);

    for(int i = 4 ; i <= n ; i++){
        dp[i] = max(dp[i-2] + Stairs[i] , dp[i-3] + Stairs[i-1] + Stairs[i]);
    }
    cout << dp[n];
    // for (int i = 0 ; i <= n ; i++){
    //     cout << dp[i] << ' ';
    // }

    delete[] dp;
    delete[] Stairs;
    return 0;
}
