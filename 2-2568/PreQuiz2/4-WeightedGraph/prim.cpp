#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// กำหนดค่า INF (Infinity) เป็น 1e9 (หนึ่งพันล้าน)
const int INF = 1e9;

// ✅ ปรับเพิ่มพารามิเตอร์ parent และ key เข้ามาแบบอ้างอิง (&) เพื่อส่งค่ากลับไปที่ main
void Prim(const vector<vector<pair<int, int>>> &adj, int V, int src, vector<int>& parent, vector<int>& key)
{
    // สร้าง priority_queue แบบ min-heap ที่เก็บคู่ {น้ำหนัก, โหนด}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // vector เก็บสถานะว่าโหนดอยู่ใน MST แล้วหรือไม่
    vector<bool> inMST(V, false);

    // เริ่มต้นค่าให้ parent และ key
    parent.assign(V, -1);
    key.assign(V, INF);

    // เริ่มต้นที่โหนด src โดยใส่น้ำหนัก 0 และโหนด src ลงใน priority_queue
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty())
    {
        // ดึงโหนดที่มีค่า key (น้ำหนักขอบ) น้อยที่สุดออกจากคิว
        int currV = pq.top().second;
        pq.pop();

        // ถ้าโหนด currV ถูกประมวลผลไปแล้ว ให้ข้าม (ป้องกันปัญหาขอบใน pq ซ้ำซ้อน)
        if (inMST[currV])
            continue;

        // ทำเครื่องหมายว่าโหนด currV อยู่ใน MST แล้ว
        inMST[currV] = true;

        // สำรวจเพื่อนบ้านทั้งหมดของโหนด currV
        for (int i = 0; i < adj[currV].size(); ++i)
        {
            int v = adj[currV][i].first;
            int w = adj[currV][i].second;

            // เงื่อนไขการอัปเดต: ถ้า v ยังไม่อยู่ใน MST และน้ำหนักขอบใหม่นี้น้อยกว่าค่า key เดิมของ v
            if (inMST[v] == false && w < key[v])
            {
                // อัปเดตค่า key ของ v ให้เป็นน้ำหนักขอบใหม่ที่น้อยกว่า
                key[v] = w;
                // ใส่คู่ {น้ำหนักใหม่, โหนด v} ลงใน priority_queue
                pq.push({key[v], v});
                // กำหนดโหนด currV เป็น parent ของ v
                parent[v] = currV;
            }
        }
    }
}

int main()
{
    int V = 5; // จำนวนโหนดในกราฟตัวอย่าง

    // สร้างรายการเพื่อนบ้าน (Adjacency List) สำหรับกราฟแบบไม่มีทิศทาง
    vector<vector<pair<int, int>>> adj(V);

    // เพิ่มเส้นเชื่อม (โหนด u, โหนด v, น้ำหนัก w) เข้ากราฟตัวอย่าง
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    int start_node = 0;
    
    // ✅ เตรียมกล่องเปล่าๆ 2 ใบไว้รับค่าจากฟังก์ชัน Prim
    vector<int> parent;
    vector<int> key;

    cout << "Running Prim's algorithm starting from node " << start_node << endl;
    
    // เรียกใช้ฟังก์ชัน Prim พร้อมแนบกล่อง parent และ key เข้าไปด้วย
    Prim(adj, V, start_node, parent, key);

    // ✅ เอาหน้าที่การ Print มาไว้ใน main 
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (int i = 0; i < V; ++i) {
        // ข้ามโหนดเริ่มต้น (เพราะไม่มี parent) และเช็คว่าโหนดนั้นไปถึงได้จริงๆ
        if (i != start_node && parent[i] != -1) {
            // โหนด i จะเชื่อมกับ parent[i] เสมอ และมีน้ำหนักเท่ากับ key[i]
            cout << parent[i] << " - " << i << " with weight: " << key[i] << endl;
        }
    }

    return 0;
}