#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int main() {
    int V, E;
    if (!(cin >> V >> E)) return 0;

    // สร้างตาราง graph
    vector<vector<int>> adj(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) adj[i][i] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w; 
        // adj[v][u] = w; // ถ้าเป็น Undirected graph
    }

    // =====================================
    // ลุย Floyd-Warshall ทับลงใน graph ตรงๆ เลย!
    // =====================================
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][k] != INF && adj[k][j] != INF) {
                    if (adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j]; // อัปเดตทับของเดิม
                    }
                }
            }
        }
    }

    // รับคำถามและเปิดตาราง graph ตอบได้เลย
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int start, end;
        cin >> start >> end;
        if (adj[start][end] == INF) cout << "INF\n";
        else cout << adj[start][end] << "\n";
    }

    return 0;
}