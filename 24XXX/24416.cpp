//https://www.acmicpc.net/problem/24416
#include <iostream>
#include <vector>

using namespace std;

int count1 = 0;
int count2 = 0;
int fib(int n){
    
    if (n == 1 || n == 2){
        count1++;
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
    
}

int fibDp(int n){
    if(n==1 || n==2) return 1;
    vector<int> f(n+1);
    f[1] = 1; f[2] = 1;
    for (int i = 3; i <= n ; i++){
        f[i] = f[i-1] + f[i-2];
        count2++;
    }
    return f[n];
}
int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    int a = fib(n);
    int b = fibDp(n);

    cout << count1 <<" "<< count2 << endl;
    
    return 0;
}
