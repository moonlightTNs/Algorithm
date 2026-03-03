#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// ฟังก์ชัน Dijkstra
vector<int> Dijkstra(vector<vector<pair<int,int>>> &adj, int n, int start)
{
    vector<int> dist(n, INF);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u])
            continue;

        for (int i = 0; i < adj[u].size(); i++) {

            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int C;
    cin >> C;

    while (C--) {

        int n, m, s, t;
        cin >> n >> m >> s >> t;

        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;

            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        // เรียกใช้ฟังก์ชัน Dijkstra
        vector<int> dist = Dijkstra(adj, n, s);

        if (dist[t] == INF)
            cout << -1 << endl;
        else
            cout << dist[t] << endl;
    }

    return 0;
}