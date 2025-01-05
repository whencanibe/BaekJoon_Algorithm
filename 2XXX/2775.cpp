#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // 0층 초기화
        for (int l = 0; l <= n; l++) {
            dp[0][l] = l;
        }

        // DP 계산
        for (int s = 1; s <= k; s++) {
            for (int t = 1; t <= n; t++) {
                dp[s][t] = dp[s][t - 1] + dp[s - 1][t];
            }
        }

        cout << dp[k][n] << endl;
    }

    return 0;
}
