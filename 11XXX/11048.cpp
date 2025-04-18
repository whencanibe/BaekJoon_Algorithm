#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    int **maze = new int *[N];
    int **dp = new int *[N];
    for (int i = 0; i < N; i++)
    {
        maze[i] = new int[M];
        dp[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    dp[0][0] = maze[0][0];
    for (int i = 1; i < M; i++)
    {
        dp[0][i] = dp[0][i - 1] + maze[0][i];
    }

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + maze[i][0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1])) + maze[i][j];
        }
    }

    cout << dp[N - 1][M - 1] << endl;

    for (int i = 0; i < N; i++)
    {
        delete[] maze[i];
        delete[] dp[i];
    }
    delete[] maze;
    delete[] dp;
    return 0;
}
