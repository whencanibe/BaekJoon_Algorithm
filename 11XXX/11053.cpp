#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N, 1); // 모든 dp[i]를 1로 초기화

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // DP 점화식 적용
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 결과: dp 배열의 최댓값
    int result = *max_element(dp.begin(), dp.end());
    cout << result;

    return 0;
}
