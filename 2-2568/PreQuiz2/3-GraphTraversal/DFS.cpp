#include <iostream>
#include <vector>

using namespace std;

// ประกาศตัวแปร global สำหรับเช็ควงวน
bool cycleFound = false; 

// ฟังก์ชัน DFS
void DFS(vector<vector<int>>& matrix, int startVertex, int V, vector<bool>& visited, vector<int>& parent) {
    visited[startVertex] = true;
    
    // พิมพ์โหนดปัจจุบันที่กำลังแวะเยี่ยมชม
    cout << startVertex << " "; 

    for (int i = 0; i < V; i++) {
        if (matrix[startVertex][i]) { 
            
            if (!visited[i]) {
                parent[i] = startVertex;
                DFS(matrix, i, V, visited, parent);
            }
            else if (parent[startVertex] != i && parent[startVertex] != -1) {
                cycleFound = true;
                
            }
        }
    }
}

int main() {
    int V, E; 
    
    // 1. รับจำนวนโหนด (V) และ จำนวนเส้นเชื่อม (E)
    // cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // 2. สร้าง Matrix ขนาด V x V และกำหนดค่าเริ่มต้นเป็น 0 (ไม่มีเส้นเชื่อม)
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // 3. วนลูปรับข้อมูลเส้นเชื่อม E เส้น
    // cout << "Enter edges (u v): \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        
        // กราฟไม่มีทิศทาง (Undirected) ต้องอัปเดตทั้งไปและกลับ
        matrix[u][v] = 1;
        matrix[v][u] = 1; 
    }

    // เตรียม Array สำหรับ visited และ parent
    vector<bool> visited(V, false);
    vector<int> parent(V, -1); 

    cycleFound = false;

    cout << "DFS Traversal: ";
    
    
    DFS(matrix, 0, V, visited, parent);
    cout << endl;

    // แสดงผลลัพธ์
    cout << "-------------------------" << endl;
    if (cycleFound) {
        cout << "Result: Cycle Detected! (ตรวจพบวงวนในกราฟ)" << endl;
    } else {
        cout << "Result: No Cycle Found. (ไม่มีวงวนในกราฟ)" << endl;
    }

    return 0;
}