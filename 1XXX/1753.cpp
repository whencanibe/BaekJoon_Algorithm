#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, int V, vector<vector<pii>>& adj){
    vector<int> distance(V+1,INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[start] = 0;
    pq.push({0, start}); // dist, vertex !!!

    while(!pq.empty()){
        int cDist = pq.top().first;
        int cVert = pq.top().second;
        pq.pop();

        if (cDist > distance[cVert]) continue;

        for (const auto& edge : adj[cVert]){
            int nextVert = edge.first;
            int weight = edge.second;

            if(distance[cVert]+weight < distance[nextVert]){
                distance[nextVert] = distance[cVert]+weight;
                pq.push({distance[nextVert],nextVert});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= V; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }

}

int main(int argc, char const *argv[])
{
    int V,E,K;
    cin >> V >> E;
    cin >> K;

    vector<vector<pii>> adj(V+1);
    for(int i = 0 ; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    dijkstra(K,V,adj);
    return 0;
}
