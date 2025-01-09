#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> adj[], bool *visited, queue<int>& q){
    int count = 0;

    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        for(int i : adj[start]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                count++;
            }
            
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> adj[N+1];
    for (int i= 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool *visited = new bool[N+1];
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int result = bfs(adj,visited,q);

    cout << result << endl;
    delete[] visited;
    return 0;
}
