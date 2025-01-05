#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 한 위치에서 증가하는거 구하고 감소하는 거 구하기
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dpIncrease(N, 1);
    vector<int> dpDecrease(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if (A[i] > A[j]){
                dpIncrease[i] = max(dpIncrease[i], dpIncrease[j] + 1);
            }
        }
    }

    for (int i = N-2 ; i >= 0 ; i--){
        for(int j = N-1; j > i ; j--){
            if (A[i] > A[j]){
                dpDecrease[i] = max(dpDecrease[i], dpDecrease[j] + 1);
            }
        }
    }

    int MAX = 0;
    for (int i = 0 ; i < N ; i++){
        MAX = max(MAX, dpIncrease[i] + dpDecrease[i] - 1);
    }

    cout << MAX;
    
    return 0;
}
