//https://www.acmicpc.net/problem/2839
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<pair<int, int> > count(N);
    // ex) 3x + 5y = 18
    int maxX = N / 3;
    int maxY = N / 5;

    bool isN = false;
    int sum = 999999999;
    for(int i = 0 ; i <= maxY; i++){
        for (int j = 0 ; j <= maxX; j++){
            int result = 5 * i + 3 * j;
            if(result == N){
                sum = min(sum,i+j);
                isN = true;
            }
        }
    }

    if (!isN) cout << -1;
    else cout << sum;
    return 0;
}
