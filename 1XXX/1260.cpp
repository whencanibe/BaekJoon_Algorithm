#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // For memset

using namespace std;

void dfs(int start, vector<int> adj[], bool visited[], vector<int> &result)
{
    visited[start] = true;
    result.push_back(start);

    for (int neighbor : adj[start])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, result);
        }
    }
}

void bfs(int start, vector<int> adj[], bool visited[], vector<int> &result)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        for (int neighbor : adj[vertex])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M, V;
    std::cin >> N >> M >> V;
    int V1, V2;
    vector<int> adj[N + 1];
    for (int i = 0; i < M; i++)
    {
        cin >> V1 >> V2;
        adj[V1].push_back(V2);
        adj[V2].push_back(V1);
    }
    for (int i = 1; i <= N; i++)
    { // 1부터 N!!! 범위 신경쓰기
        sort(adj[i].begin(), adj[i].end());
    }

    bool visited[N + 1];
    memset(visited, false, sizeof(visited));
    vector<int> dfsResult;
    dfs(V, adj, visited, dfsResult);

    memset(visited, false, sizeof(visited));
    vector<int> bfsResult;
    bfs(V, adj, visited, bfsResult);

    for (int i : dfsResult)
    {
        cout << i << " ";
    }

    cout << endl;

    for (int i : bfsResult)
    {
        cout << i << " ";
    }
    return 0;
}
