#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int M, N;
    queue<pair<int, int>> q;
    cin >> M >> N;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<int>> tomato(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<int> days;
    int maxDay = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            {
                q.push({j, i});
                visited[i][j] = true;
                days.push(0);
            }
        }
    }

    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int DAY = days.front();
        days.pop();

        maxDay = max(maxDay, DAY);
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx] || tomato[ny][nx] == -1)
                continue;

            if (tomato[ny][nx] == 0)
            {
                q.push({nx, ny});
                visited[ny][nx] = true;
                tomato[ny][nx] = 1;
                days.push(DAY + 1);
            }
            // else if (tomato[ny][nx] == 1)
            // {
            //     q.push({nx, ny});
            //     visited[ny][nx] = true;
            // }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << tomato[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(tomato[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << maxDay;
    return 0;
}