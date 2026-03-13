#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
  int n, m, s, t;
  if (!(cin >> n >> m >> s >> t))
    return 0;

  // roads[u] = list of pairs (v, weight) representing edges
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // ถนนสามารถเดินทางสวนกันได้ (Bi-directional)
  }

  // dist[i] เก็บระยะทางที่สั้นที่สุดจาก s ไปยัง i
  vector<int> dist(n + 1, INF);

  // priority_queue สำหรับ Dijkstra: {ระยะทาง, โหนด} แบบ min-heap
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // เริ่มต้นที่จุด S
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    // ถ้าระยะทางปัจจุบันในคิวมากกว่าที่เคยพบ ให้ข้ามไป
    if (d > dist[u])
      continue;

    // ถ้าถึงจุดหมาย T แล้ว สามารถ break ได้เลยเพราะพบเส้นทางสั้นสุดแล้ว
    if (u == t)
      break;

    // สำรวจถนนทุกเส้นที่เชื่อมต่อกับ u
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int weight = adj[u][i].second;

      // Relaxation
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  // พิมพ์ระยะทางที่สั้นที่สุดไปยังจุดหมาย T
  cout << dist[t] << endl;

  return 0;
}
