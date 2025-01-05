#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    
    cin >> N;
    vector<vector<int> > house(N+1,vector<int>(3,0));
    for(int i = 1 ; i <= N ; i++){
        
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    vector<vector<int> > dp(N+1,vector<int>(3,0));
    
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];

    for(int i = 2 ; i <= N ; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + house[i][2];
    }   

    cout << min(min(dp[N][0],dp[N][1]),dp[N][2]);
    
    return 0;
}
