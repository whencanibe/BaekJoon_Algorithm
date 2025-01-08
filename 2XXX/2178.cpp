#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // For memset

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    pair<int, int> dir[4] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
    string str;
    vector<vector<char> > maze(N + 1, vector<char>(M + 1, 0));
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(N+1, vector<bool>(M+1,false));

    vector<vector<int>> distance(N + 1, vector<int>(M + 1, 0)); // 거리 저장!!!
    
    for (int i = 1 ; i <= N ; i++){
        cin >> str;
        for(int j = 1; j <= M ; j++){
            maze[i][j] = str[j-1];
        }
    }

     // 시작점
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    distance[1][1] = 1; // 시작 칸 포함

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int j = 0 ; j < 4 ; j++){
            int u = x + dir[j].first;
            int v = y + dir[j].second;
            
            if(u < 1 || u > N || v < 1 || v > M || visited[u][v] || maze[u][v] == '0') continue;

            // 방문 처리 및 거리 갱신
            visited[u][v] = true;
            distance[u][v] = distance[x][y] + 1; // 이전 거리 + 1
            q.push(make_pair(u, v));
        } 
        
    }

    cout << distance[N][M] << endl;

    return 0;
}
