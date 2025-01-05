#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;

    vector<int> value(n,0);
    for (int i = 0 ; i < n ; i++){
        cin >> value[i];
    }

    vector<int> dp(k+1,0);

    dp[0] = 1;
    //각 동전을 사용할 때의 경우의 수를 구해서 누적시키기
    for (int coin : value){
        for (int i = coin ; i <= k ; i++){
            dp[i] = dp[i] + dp[i-coin];
        }
    }

    cout << dp[k];

    return 0;
}
