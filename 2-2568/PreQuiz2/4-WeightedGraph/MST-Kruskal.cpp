#include <iostream>
#include <queue>
#include <vector>


using namespace std;

vector<int> parentSet;

// find: หาหัวกลุ่ม (root) ของ node
int find_root(int i) {
  if (parentSet[i] == i)
    return i;
  return find_root(parentSet[i]);
}

// union_set: รวมกลุ่มของ x และ y เข้าด้วยกัน
void union_set(int x, int y) {
  int xroot = find_root(x);
  int yroot = find_root(y);
  parentSet[xroot] = yroot;
}

// is_cycle: เช็กว่าเพิ่ม edge (u, v) แล้วจะเกิด cycle ไหม
bool is_cycle(int u, int v) {
  int x = find_root(u);
  int y = find_root(v);
  return (x == y) ? true : false;
}

int main() {

  int n, m;
  cin >> n >> m;

  // priority_queue เก็บ edge เป็น (weight, (u, v)) แบบ min-heap
  // first  = weight ของเส้นทาง
  // second = (u, v) คือจุดต้นทาง-ปลายทาง
  priority_queue<pair<long , pair<int, int>>,
                 vector<pair<long, pair<int, int>>>,
                 greater<pair<long, pair<int, int>>>>
      pq;

  for (int i = 0; i < m; i++) {
    int u, v;
    long w;
    cin >> u >> v >> w;
    pq.push({w, {u, v}}); // ดันเข้า pq เพื่อจัดเรียงตามน้ำหนักอัตโนมัติ
  }

  parentSet.resize(n + 1);

  for (int i = 1; i <= n; i++)
    parentSet[i] = i;

long totalWeight = 0; // น้ำหนักรวมของ MST
  int edgeUsed = 0;          // จำนวนเส้นทางที่เลือกมาแล้ว

  // ดึง edge จาก priority_queue ทีละเส้น (น้ำหนักน้อยสุดก่อน)
  while (edgeUsed < n - 1 && !pq.empty()) {

    long w = pq.top().first;   // weight
    int u = pq.top().second.first;  // จุดต้นทาง
    int v = pq.top().second.second; // จุดปลายทาง
    pq.pop();

    if (!is_cycle(u, v)) { // ถ้ายังไม่อยู่กลุ่มเดียวกัน แปลว่าไม่เกิด cycle
      union_set(u, v);     // รวมกลุ่ม
      totalWeight += w;    // บวกน้ำหนักเข้า MST
      edgeUsed++;
    }
  }

  long totalFlags = totalWeight - (n - 1);

  cout << totalFlags << endl;

  return 0;
}
