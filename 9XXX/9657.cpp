#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    bool* dp = new bool[N + 1];

    //true : sk , false : cy
    dp[0] = false;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for(int i = 5 ; i < N + 1 ; i++){
        if (!dp[i-1] || !dp[i-3] || !dp[i-4]){
            dp[i] = true;
        } else{
            dp[i] = false;
        }
    }

    if(dp[N]){
        printf("SK\n");
    } else {
        printf("CY\n");
    }

    delete[] dp;
    return 0;
}
