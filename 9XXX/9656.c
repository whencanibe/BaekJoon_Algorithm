#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int* dp = (int*)malloc(sizeof(int) * (N + 1));

    for (int i = 0 ; i < N + 1; i++){
        dp[i] = 0;
    }

    // 1 : CY , 0 : SK
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;

    for (int i = 4 ; i < N + 1 ; i++){
        if (dp[i-1] == 0|| dp[i-3] == 0){
            dp[i] = 1;
        }
    }

    if (dp[N]){
        printf("CY");
    } else {
        printf("SK");
    }
    free(dp);
    return 0;
}
