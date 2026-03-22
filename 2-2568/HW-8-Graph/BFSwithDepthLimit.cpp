#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ฟังก์ชัน BFS แบบจำกัดความลึก m
int BFS(const vector<vector<int>>& graph, int V, int start, int m) {
    
    vector<int> level(V + 1, -1);
    queue<int> q;

    level[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int currentV = q.front();
        q.pop();

        // ถ้าถึงระดับ m แล้ว ไม่ต้องขยายต่อ
        if (level[currentV] == m)
            continue;

        for (int i = 0; i < graph[currentV].size(); i++) {
            int neighbor = graph[currentV][i];
            if (level[neighbor] == -1) {
                level[neighbor] = level[currentV] + 1;
                q.push(neighbor);
            }
        }
    }

    // นับ vertex ที่ไม่ครอบคลุม
    int countUncovered = 0;
    for (int i = 1; i <= V; i++) {
        if (level[i] == -1 || level[i] > m) {
            countUncovered++;
        }
    }

    return countUncovered;
}

int main() {

    int V;
    cin >> V;

    vector<vector<int>> graph(V + 1);

    // อ่าน edge จนเจอ 0 0
    while (true) {
        int p, q;
        cin >> p >> q;

        if (p == 0 && q == 0)
            break;

        graph[p].push_back(q);  // directed graph
    }

    int k, m;
    cin >> k >> m;

    cout << BFS(graph, V, k, m) << endl;

    return 0;
}