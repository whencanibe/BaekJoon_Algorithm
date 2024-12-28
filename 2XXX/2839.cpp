//https://www.acmicpc.net/problem/2839
// 0 % 5 == 0
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int count = 0;
    while(N>=0){
        if(N % 5 == 0){
            count += N / 5;
            cout << count;
            return 0;
        }
        N -= 3;
        count++;
    }
    cout << -1;
    //if(N>0) cout << -1;
    //else cout << count;
    return 0;
}
