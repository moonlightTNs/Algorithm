#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>> &graph, int start ,int V)
{
    vector<bool> visited(V + 1, false);
    vector<int> parent(V + 1, -1); // 1. เพิ่ม parent array (ค่าเริ่มต้น -1)

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int currV = q.front();
        q.pop();
        cout << currV << " ";
        for (int i = 0; i < (int)graph[currV].size(); i++) 
        {
            int nb = graph[currV][i]; // ดึงโหนดเพื่อนบ้านตำแหน่งที่ i ออกมาเก็บไว้ใน v

            if (!visited[nb]) // ถ้า v ยังไม่ถูกเยี่ยมชม
            {
                q.push(nb);
                visited[nb] = true;
                parent[nb] = currV; // 2. อัปเดต parent ว่า v ถูกค้นพบมาจากโหนด currV
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin >> start;

    bfs(graph, start, V);

    cout << endl;
    return 0;
}