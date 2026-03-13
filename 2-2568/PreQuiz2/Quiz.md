# แนวข้อสอบ PreQuiz 2 (คัดเลือกจากโจทย์ HW-6 ถึง HW-10)

เอกสารนี้บรรจุคำถามแนวข้อสอบ 2-3 ข้อต่อหัวข้อ ที่คัดกรองมาจากแหล่งปัญหาใน Homework ท้ายบท เพื่อให้ฝึกทำก่อนสอบ พร้อม Source Code ตัวอย่างในการแก้ปัญหา

---

## Topic 1: Backtracking (จาก HW-6)

**1. N-Queens Problem (Modified Base)**
*โจทย์:* จงเขียนโปรแกรมเชิง Backtracking เพื่อหาจำนวนรูปแบบของกระดานตารางหมากรุกขนาด $N \times N$ โดยกติกาคือให้วาง Queen จำนวน $N$ ตัวลงในกระดาน โดยที่ควีนแต่ละตัวต้องไม่ชนกันในแนวตั้ง แนวนอน รวมถึงไม่ทับกันใน **แนวทแยง (Diagonal)** (ให้หาจำนวนคำตอบสำหรับช่องกระดานขนาด 4x4)  
*สิ่งที่จะวัด:* การสร้าง State Space Tree ดักเงื่อนไขแบบ Backtrack และเขียน `isSafe` เพื่อตรวจสอบแนวทแยง
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include<iostream>
#include<cmath>

using namespace std;

int count = 0;  // นับจำนวน solution
int n = 4;      // ขนาดกระดาน 4x4

// ตรวจว่า queen ชนกันในแนวทแยงหรือไม่
// x[i] = column ของ queen ใน row i
bool isSafe(int x[], int row) {
    for (int i = 1; i < row; i++) {
        // ตรวจแนวทแยง: ถ้า |row1 - row2| == |col1 - col2| แสดงว่าอยู่แนวทแยงเดียวกัน
        if (abs(x[i] - x[row]) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// แสดงกระดาน
void printBoard(int x[]) {
    cout << "Solution " << count << ":" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << "Position: ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl << endl;
}

void nqueens(int x[], int start, int end) {
    if (start == end) {
        // ตรวจว่า queen ตัวสุดท้ายชนแนวทแยงไหม
        if (isSafe(x, end)) {
            count++;
            printBoard(x);
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(x[start], x[i]);
        // Backtracking: ตรวจก่อนไปต่อ ถ้าไม่ safe ก็ไม่ต้องไปลึกกว่านี้
        if (isSafe(x, start)) {
            nqueens(x, start + 1, end);
        }
        swap(x[start], x[i]);
    }
}

int main() {
    // x[i] = column ของ queen ใน row i
    // ใช้ permutation ของ {1,2,3,4} ทำให้ไม่ต้องตรวจ row และ column ซ้ำ
    int x[] = {-1, 1, 2, 3, 4};

    cout << "=== N-Queens Problem (4x4) ===" << endl << endl;
    
    nqueens(x, 1, n);
    
    cout << "Total solutions: " << count << endl;
    return 0;
}
```
</details>

**2. Permutation with Constraint**
*โจทย์:* นำตัวเลข $\{1, 2, 3, 4, 5\}$ มาสร้าง Permutation (การสับเปลี่ยนตำแหน่งทั้งหมด) แต่ให้มีข้อแม้ว่า **"ตัวเลข 1 กับ 3 ห้ามอยู่ข้างติดกัน"** โดยให้แสดง Permutation ที่ตรงเงื่อนไขและสรุปยอดจำนวนรูปแบบ  
*สิ่งที่จะวัด:* ความเข้าใจในการทำ Swap permutation tree และกระบวนการตัดกิ่ง (Pruning) หากไปละเมิดเงื่อนไข
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include<iostream>

using namespace std;

int count = 0;  // global counter

void permute(int x[], int start, int end) {
    if (start == end) {
        bool closeNum = false;
        // ตรวจว่า 1 กับ 3 อยู่ติดกันหรือไม่
        for (int i = 1; i < end; i++) {  // i < end เพราะจะเข้าถึง x[i+1]
            if ((x[i] == 1 && x[i + 1] == 3) || (x[i] == 3 && x[i + 1] == 1)) {
                closeNum = true;
                break;
            }
        }
        
        if (!closeNum) {
            count++;
            for (int i = 1; i <= end; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main() {
    int n = 5;
    int x[] = {-1, 1, 2, 3, 4, 5};

    permute(x, 1, n);
    
    cout << "Total permutations (1 and 3 not adjacent): " << count << endl;
    return 0;
}
```
</details>

**3. Knapsack (Binary Subset Sum)**
*โจทย์:* กำหนดกระเป๋าใบหนึ่งรับน้ำหนักได้ $K$ กิโลกรัม และมีของ $N$ ชิ้นที่มีขนาดน้ำหนัก (Weight) และมีราคาประเมิน (Value) แตกต่างกันไป โดยให้เลือกของแบบ 0/1 (เลือกชิ้นเต็มหรือไม่เลือก) จงหาวิธีเลือกที่ได้ Value มากที่สุดไม่ให้กระเป๋าแตก  
*สิ่งที่จะวัด:* การเขียน Binary tree (`x[i] = 1`, `x[i] = 0`) แล้วส่งอาร์เรย์มาเช็คใน Base case ว่าหากน้ำหนัก $\le K$ ให้จับคอยอัปเดต `MaxV` ไปเรื่อยๆ
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
using namespace std;

int MaxV = INT_MIN;
int V[100];  // มูลค่าสินค้า 
int W[100];  // น้ำหนักสินค้า 
int k;       // น้ำหนักสูงสุดที่ถุงรับได้
int n;       // จำนวนสินค้า

void knap_print(int x[])
{
    int sum_w = 0;
    int sum_v = 0;

    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            sum_w += W[i];
            sum_v += V[i];
        }
    }

    if (sum_w <= k)
    {
        if (sum_v > MaxV)
        {
            MaxV = sum_v;
        }
    }
}

void subsetbinary(int x[], int l, int r)
{
    if (l == r)
    {
        knap_print(x);
    }
    else
    {
        x[l + 1] = 1;
        subsetbinary(x, l + 1, r);
        x[l + 1] = 0;
        subsetbinary(x, l + 1, r);
    }
}

int main()
{
    // k (น้ำหนักสูงสุดของถุง)
    cin >> k;
    
    // มูลค่าสินค้า 4 ชิ้น
    n = 4;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
    }
    
    // น้ำหนักสินค้า 4 ชิ้น
    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
    }

    int x[n + 1];

    subsetbinary(x, 0, n);
    cout << MaxV << endl;

    return 0;
}
```
</details>

---

## Topic 2: Greedy Algorithm (จาก HW-7)

**1. Fractional Knapsack Problem**
*โจทย์:* กระเป๋ารับน้ำหนักได้ $W$ โดยมีของอยู่ $N$ ชิ้นสามารถ "ซอยย่อย" (แบ่งสัดส่วน) ได้ตามน้ำหนักที่มี จงหาจุดและจำนวนเปอร์เซ็นต์ของของที่ลงไปอยู่ในกระเป๋าเพื่อให้ได้มูลค่าเยอะที่สุด  
*สิ่งที่จะวัด:* การคำนวณสัดส่วน (Ratio) อัตราความคุ้มค่าแบบ Value/Weight การเรียงลำดับ Sort Fraction และการลบเศษส่วนในของชิ้นสุดท้าย
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
using namespace std;

int partition(double ratio[], double weight[], double value[], int index[],
              int low, int high) {
  double pivot = ratio[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (ratio[j] >= pivot) {
      swap(ratio[i], ratio[j]);
      swap(weight[i], weight[j]);
      swap(value[i], value[j]);
      swap(index[i], index[j]);
      i++;
    }
  }
  swap(ratio[i], ratio[high]);
  swap(weight[i], weight[high]);
  swap(value[i], value[high]);
  swap(index[i], index[high]);
  return i;
}

// Quick Sort ตาม ratio จากมากไปน้อย
void quickSort(double ratio[], double weight[], double value[], int index[],
               int low, int high) {

  if (low < high) {
    int pivotIdx = partition(ratio, weight, value, index, low, high);
    quickSort(ratio, weight, value, index, low, pivotIdx - 1);
    quickSort(ratio, weight, value, index, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  double W;
  cin >> n >> W;

  double weight[10], value[10], ratio[10], fraction[10];
  int index[10]; // เก็บ index เดิมไว้

  // รับ input น้ำหนักและมูลค่า
  for (int i = 0; i < n; i++)
    cin >> weight[i];
  for (int i = 0; i < n; i++)
    cin >> value[i];

  // คำนวณ value/weight ratio และเก็บ index เดิม
  for (int i = 0; i < n; i++) {
    ratio[i] = value[i] / weight[i];
    index[i] = i;
    fraction[i] = 0.0; // เริ่มต้น ยังไม่เลือก item ใดเลย
  }

  // Sort ตาม ratio จากมากไปน้อย (Quick Sort)
  quickSort(ratio, weight, value, index, 0, n - 1);

  // Greedy: เลือก item ที่มี ratio สูงสุดก่อน
  double remaining = W;
  double totalValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (remaining <= 0)
      break;

    if (weight[i] <= remaining) {
      // เลือกทั้งชิ้น
      fraction[index[i]] = 1.0;
      totalValue += value[i];
      remaining -= weight[i];
    } else {
      // เลือกบางส่วน
      double frac = remaining / weight[i];
      fraction[index[i]] = frac;
      totalValue += value[i] * frac;
      remaining = 0;
    }
  }

  // แสดงสัดส่วนการเลือก item ตามลำดับเดิม (ทศนิยม 2 ตำแหน่ง)
  cout << fixed;
  cout.precision(2);
  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << " ";
    cout << fraction[i];
  }
  cout << endl;

  // แสดงมูลค่ารวมสูงสุด
  cout << totalValue << endl;

  return 0;
}
```
</details>

**2. Minimum Platforms Problem**
*โจทย์:* ที่สถานีรถไฟแห่งหนึ่ง มีกำหนดการเวลาเข้าเทียบชานชาลา (Arrival array) และกำหนดการเวลาย้ายออก (Departure array) ของรถไฟจำนวน $N$ ขบวน จงหาจำนวนชานชาลา "ขั้นต่ำ" ควบเวลาที่มีทั้งหมดที่สถานีแห่งนี้ต้องเปิดให้บริการพร้อมกันเพื่อให้รถไฟทุกคันได้จอดโดยไม่ต้องรอ  
*สิ่งที่จะวัด:* การใช้ Greedy แบบ 2 Pointers แบ่ง Sort ทั้งอาร์เรย์เข้าและออกแยกกัน แล้วเลื่อนตัวนับทีละ pointer
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
using namespace std;

int partition(double arr[], int low, int high) {
  double pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

void quickSort(double arr[], int low, int high) {
  if (low < high) {
    int pivotIdx = partition(arr, low, high);
    quickSort(arr, low, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  cin >> n;

  double arrival[500], departure[500];
  for (int i = 0; i < n; i++) {
    cin >> arrival[i] >> departure[i];
  }

  // Sort เวลามาถึงและเวลาออกแยกกัน (น้อยไปมาก)
  quickSort(arrival, 0, n - 1);
  quickSort(departure, 0, n - 1);

  // Greedy: ใช้ 2 pointer นับจำนวน platform ที่ต้องใช้
  int platforms = 0, maxPlatforms = 0;
  int i = 0, j = 0;

  while (i < n && j < n) {
    if (arrival[i] < departure[j]) {
      // รถไฟมาถึง → ต้องการ platform เพิ่ม
      platforms++;
      if (platforms > maxPlatforms)
        maxPlatforms = platforms;
      i++;
    } else {
      // รถไฟออก → คืน platform
      platforms--;
      j++;
    }
  }

  cout << maxPlatforms << endl;

  return 0;
}
```
</details>

---

## Topic 3: Graph Traversal (จาก HW-8)

**1. Flood Fill 2-Dimension Grid**
*โจทย์:* ให้ตาราง $N \times M$ สมมติประกอบด้วยสีต่างๆ เป็นตัวอักษร หากเทสีตรงพิกัดกำหนด (X, Y) จงหาจำนวนพื้นที่ (Cell) ติดต่อกันจากพิกัดดังกล่าวตามทิศ 4 ด้านที่มีสีแบบเดียวกันทั้งหมด มีทั้งหมดกี่ช่อง  
*สิ่งที่จะวัด:* การสร้าง Implicit Graph กวาดคิว Queue 2D สี่ทิศทาง (dx, dy arrays) และ BFS ขยายกิ่งหาเป้าหมายเดิม
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ฟังก์ชัน BFS สำหรับ Flood Fill
int BFS(vector<string>& image, int N, int M, int startX, int startY) {

    char originalColor = image[startX][startY];

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;

    q.push({startX, startY});
    visited[startX][startY] = true;

    int count = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        count++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && image[nx][ny] == originalColor) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return count;
}

int main() {

    int N, M;
    cin >> N >> M;

    vector<string> image(N);

    for (int i = 0; i < N; i++) {
        cin >> image[i];
    }

    int X, Y;
    cin >> X >> Y;

    // แปลงเป็น 0-based index
    X--;
    Y--;

    cout << BFS(image, N, M, X, Y) << endl;

    return 0;
}
```
</details>

**2. BFS with Depth Limit**
*โจทย์:* จากกราฟเส้นเชื่อมมีทิศทาง หากเริ่มกระจายตัวที่ Source Node โดยผู้ตรวจสอบมีกำลังจำกัด คือเดินลึกได้สูงสุดแค่ระดับชั้น (Depth limit) = $m$ อยากทราบว่ามีจำนวนจุดยอดในเครือข่ายนี้กี่จุดที่ไม่สามารถเดินแตะไปถึงได้  
*สิ่งที่จะวัด:* การนับระยะ Level ขั้นตอน BFS (Dist[Node]) ที่ซุดกรอบอยู่ที่ตัวแปร limit และรวบยอดจำนวน Node นอกขอบข่ายหรือ Node Unreachable
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ฟังก์ชัน BFS แบบจำกัดความลึก m
int BFS(const vector<vector<int>>& graph, int V, int start, int m) {
    
    vector<int> dist(V + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // ถ้าถึงระดับ m แล้ว ไม่ต้องขยายต่อ
        if (dist[current] == m)
            continue;

        for (int neighbor : graph[current]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // นับ vertex ที่ไม่ครอบคลุม
    int countUncovered = 0;
    for (int i = 1; i <= V; i++) {
        if (dist[i] == -1 || dist[i] > m) {
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
```
</details>

---

## Topic 4: Weighted Graph & Shortest Paths (จาก HW-9)

**1. Kruskal's Minimum Spanning Tree**
*โจทย์:* ให้กราฟไม่มีทิศทางจำนวน $N$ node $M$ edge แจกแจง Edge น้ำหนักต่างๆ มาให้ จงทำการต่อให้เป็น Tree กิ่งเดี่ยวที่มีน้ำหนักโดยรวมทั้งหมดประหยัดที่สุด และจงหาว่า น้ำหนักรวมนั้น เอาไปลบหักออกจากจำนวน edge ($N-1$) จะได้ค่าส่วนต่างเหลือเท่าไหร่  
*สิ่งที่จะวัด:* ความเข้าใจในการหา Edge Sort เข้า MinHeap และเซต Union-Find ที่ป้องกันลูปแบบ Cycle
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> parentSet;

// find: หาหัวกลุ่ม (root) ของ node
int find_set(int i) {
    if (parentSet[i] == i)
        return i;
    return find_set(parentSet[i]);
}

// union_set: รวมกลุ่มของ x และ y เข้าด้วยกัน
void union_set(int x, int y) {
    int xroot = find_set(x);
    int yroot = find_set(y);
    parentSet[xroot] = yroot;
}

// is_cycle: เช็กว่าเพิ่ม edge (u, v) แล้วจะเกิด cycle ไหม
bool is_cycle(int u, int v) {
    int x = find_set(u);
    int y = find_set(v);
    return (x == y) ? true:false ;
}

int main() {

    int n, m;
    cin >> n >> m;

    // priority_queue เก็บ edge เป็น (weight, (u, v)) แบบ min-heap
    // first  = weight ของเส้นทาง
    // second = (u, v) คือจุดต้นทาง-ปลายทาง
    priority_queue<
        pair<long long, pair<int,int>>,
        vector<pair<long long, pair<int,int>>>,
        greater<pair<long long, pair<int,int>>>
    > pq;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        pq.push({w, {u, v}}); // ดันเข้า pq เพื่อจัดเรียงตามน้ำหนักอัตโนมัติ
    }

    parentSet.resize(n + 1);

    for (int i = 1; i <= n; i++)
        parentSet[i] = i;

    long long totalWeight = 0;    // น้ำหนักรวมของ MST
    int edgeUsed = 0;             // จำนวนเส้นทางที่เลือกมาแล้ว

    // ดึง edge จาก priority_queue ทีละเส้น (น้ำหนักน้อยสุดก่อน)
    while (edgeUsed < n - 1 && !pq.empty()) {

        long long w = pq.top().first;                  // weight
        int u = pq.top().second.first;                 // จุดต้นทาง
        int v = pq.top().second.second;                // จุดปลายทาง
        pq.pop();

        if (!is_cycle(u, v)) {                         // ถ้ายังไม่อยู่กลุ่มเดียวกัน แปลว่าไม่เกิด cycle
            union_set(u, v);                           // รวมกลุ่ม
            totalWeight += w;                          // บวกน้ำหนักเข้า MST
            edgeUsed++;
        }
    }

    long long totalFlags = totalWeight - (n - 1);

    cout << totalFlags << endl;

    return 0;
}
```
</details>

**2. Multi-Source Dijkstra (Hospital Location)**
*โจทย์:* มีชุมชนเป็น Graph อยู่ $N$ เขตที่มีถนนเป็น Weight ระยะทาง และมีเขตที่เป็นโรงพยาบาลเดิมอยู่ $F$ แห่ง รัฐต้องการสร้างโรงพยาบาลเพิ่มอีก 1 แห่ง (จากพื้นที่เก่าที่ยังไม่มีโรงพยาบาล) เพื่อให้เขตประชากรที่มีเส้นทางห่างไกลโรงพยาบาลที่สุด ประสบการณ์ระยะทางน้อยที่สุด (Minimize Max-Distance) จงหาตำแหน่งสร้างโรงพยาบาลใหม่ที่ดีที่สุด  
*สิ่งที่จะวัด:* Multi-source Dijkstra (โยนหลาย Node เป็นเริ่มต้นระยะ 0 ในคิว) และลูปหาคำตอบเปรียบเทียบ
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// คำนวณ "ระยะทางไกลที่สุด" จากทุกเขต ไปยังโรงพยาบาลที่ใกล้ที่สุด
// เมื่อเราเพิ่มโรงพยาบาลใหม่ที่เขต newHospital
int maxDistanceWithNewHospital(int n,const vector<vector<pair<int, int>>> &roads,const vector<int> &oldHospitals,int newHospital)
{
    vector<int> dist(n + 1, INF);

    // priority_queue สำหรับ Dijkstra: {ระยะทาง, เขต}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    // ใส่โรงพยาบาลเดิมทุกแห่งเข้าไปเป็นแหล่งเริ่มต้นระยะทาง 0
    for (int i = 0; i < oldHospitals.size(); i++)
    {
        dist[oldHospitals[i]] = 0;
        pq.push({0, oldHospitals[i]});
    }

    // ใส่โรงพยาบาลใหม่
    dist[newHospital] = 0;
    pq.push({0, newHospital});

    // Dijkstra: หา shortest path จากโรงพยาบาลที่ใกล้ที่สุด
    while (!pq.empty())
    {

        int currentDist = pq.top().first;
        int area = pq.top().second;
        pq.pop();

        if (currentDist > dist[area])
            continue;

        for (int i = 0; i < roads[area].size(); i++)
        {
            int nextArea = roads[area][i].first;
            int length = roads[area][i].second;

            if (dist[area] + length < dist[nextArea])
            {
                dist[nextArea] = dist[area] + length;
                pq.push({dist[nextArea], nextArea});
            }
        }
    }

    // ดูว่า "เขตที่ไกลที่สุด" อยู่ห่างโรงพยาบาลเท่าไร
    int maxDist = 0;
    for (int i = 1; i <= n; i++)
        maxDist = max(maxDist, dist[i]);

    return maxDist;
}

int main()
{

    int f, n; // f = จำนวนเขตที่มีโรงพยาบาลเดิม, n = จำนวนเขตทั้งหมด
    cin >> f >> n;

    vector<int> hospitals(f); // รายชื่อเขตที่มีโรงพยาบาลเดิม
    vector<bool> hasHospital(n + 1, false);

    for (int i = 0; i < f; i++)
    {
        cin >> hospitals[i];
        hasHospital[hospitals[i]] = true;
    }

    // roads[u] = รายการถนนจากเขต u ไปยังเขตอื่น ๆ (ปลายทาง, ระยะทาง)
    vector<vector<pair<int, int>>> roads(n + 1);

    // อ่านถนนทั้งหมด (ตามโจทย์ให้มาจำนวนหนึ่งบรรทัด)
    for (int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        roads[x].push_back({y, r});
        roads[y].push_back({x, r});
    }

    int bestLocation = 1;  // เขตที่ควรตั้งโรงพยาบาลใหม่
    int bestMaxDist = INF; // ระยะทางไกลที่สุด (ที่น้อยที่สุดเท่าที่หาได้)

    // ลองตั้งโรงพยาบาลใหม่ที่ทุกเขตที่ยังไม่มีโรงพยาบาลเดิม
    for (int candidate = 1; candidate <= n; candidate++)
    {

        if (hasHospital[candidate])
            continue; // ข้ามเขตที่มีโรงพยาบาลเดิมแล้ว

        int currentMaxDist = maxDistanceWithNewHospital(n, roads, hospitals, candidate);

        // ถ้า candidate นี้ทำให้เขตที่ไกลที่สุดใกล้ลง ก็เลือกตัวนี้
        if (currentMaxDist < bestMaxDist)
        {
            bestMaxDist = currentMaxDist;
            bestLocation = candidate;
        }
    }

    cout << bestLocation << endl;

    return 0;
}
```
</details>

**3. Shortest Path (Trainee Postman / บุรุษไปรษณีย์ฝึกหัด)**
*โจทย์:* บุรุษไปรษณีย์ฝึกหัดในเมืองหรรษา ต้องส่งจดหมายด่วนจากที่ทำการไปรษณีย์ (จุดเริ่มต้น S) ไปยังบ้านนายกเทศมนตรี (จุดหมาย T) โดยเมืองมีสถานที่ N แห่ง และถนนเชื่อม M เส้น (เดินทางสวนกันได้) แต่ละเส้นมีระยะทาง W ไม่เท่ากัน จงหาระยะทางที่สั้นที่สุดเพื่อไปให้ถึงที่หมายให้เร็วที่สุด
*สิ่งที่จะวัด:* การประยุกต์ใช้ Dijkstra's Algorithm เพื่อหาระยะทางที่สั้นที่สุดแบบ Single-Source Shortest Path บนกราฟที่ไม่มีทิศทาง (Undirected Weighted Graph)
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return 0;

    // roads[u] = รายการถนนจาก u ไป v พร้อมระยะทาง
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // ถนนสามารถเดินทางสวนกันได้
    }

    // dist[i] เก็บระยะทางที่สั้นที่สุดจาก s ไปยัง i
    vector<int> dist(n + 1, INF);
    
    // priority_queue สำหรับ Dijkstra แบบ min-heap: {ระยะทาง, โหนด}
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

    // เริ่มต้นที่จุด S
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == t) break; // พบจุดหมายแล้ว

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[t] << endl;

    return 0;
}
```
</details>

---

## Topic 5: Dynamic Programming (จาก HW-10)

**1. Coin Change Combination Problem**
*โจทย์:* มีเหรียญทั้งหมด $K$ ประเภทแต่ละชนิดมีโควต้าเหรียญไม่จำกัด คุณต้องทอนเงินจำนวน $N$ บาท สามารถสลับทำ Combination การทอนให้ยอดเท่ากับ $N$ ได้ทั้งสิ้นกี่รูปแบบ?  
*สิ่งที่จะวัด:* นิยาม DP Table อาเรย์เก็บจำนวนวิธี `dp[j] += dp[j - coin[i]]` โดยใช้ Loop ประเภทเหรียญซ้อน Loop ยอดรวม
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
using namespace std;

long long coinChange(int n, int k, int coin[])
{
    long long dp[100001];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < k; i++)
    {
        for (int j = coin[i]; j <= n; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int coin[5001];

    for (int i = 0; i < k; i++)
    {
        cin >> coin[i];
    }
    cout << coinChange(n, k, coin);
}
```
</details>

**2. Maximum Path in Grid Cost**
*โจทย์:* เราสามารถเดินบน Grid เมทริกซ์ 2 มิติ ได้เพียงแค่ทิศตกลงมา (Down) หรือเคลื่อนขวา (Right) ต้นทางเดินจากพิกัดบนสุดขวาไปหาปลายทางล่างซ้าย ทุกๆ Cell จะมี Cost เป็นค่าผ่านทางซ่อนอยู่ จงประเมิน DP หาวิธีการใช้ค่าผ่านทางต่ำสุดที่จะบรรลุปลาทาง  
*สิ่งที่จะวัด:* การสร้าง 2D DP Table ที่ `S(i,j) = min(S(i-1,j), S(i,j-1)) + cost[i][j]` แบบ Top-Down memoization หรือ Bottom-Up
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <climits>
using namespace std;

int cost[51][51];
int dp[51][51];
int r1, c1; // start position (x1, y1)

int S(int i, int j)
{
    if(i == r1 && j == c1)       // ถึงจุดเริ่มต้น (x1, y1)
        return cost[r1][c1];

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = INT_MAX;
    int left = INT_MAX;

    if(i > r1)                   // ยังไม่ถึงแถวเริ่มต้น
        up = S(i - 1, j);

    if(j > c1)                   // ยังไม่ถึงคอลัมน์เริ่มต้น
        left = S(i, j - 1);

    dp[i][j] = min(up, left) + cost[i][j];

    return dp[i][j];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i][j];

    int x1, y1, x2, y2;          // x1,y1 = เริ่มต้น, x2,y2 = สิ้นสุด
    cin >> x1 >> y1 >> x2 >> y2;
    r1 = x1; c1 = y1;

    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
            dp[i][j] = -1;

    cout << S(x2, y2);       // หา min cost จาก (x1,y1) ถึง (x2,y2)
}
```
</details>

**3. 0/1 Knapsack (DP Version)**
*โจทย์:* การแก้ไขปัญหา Knapsack หาว่าด้วยเงินโควต้าจำกัด คุณจะซื้อของ $N$ ชิ้นอย่างไรให้ได้ "จำนวนชิ้น" สูงที่สุด หรือ "มูลค่าสูงที่สุด" (แบบเอาไม่เอา)   
*สิ่งที่จะวัด:* การใช้ DP อะเรย์แบบ 1 มิติ `dp[j] = max(dp[j], dp[j-price[i]] + 1)` แต่ต้องจำไว้เสมอว่าต้องวนลูปตัวแปรเงินก้อน J แบบ *"ย้อนกลับ"* เพื่อไม่ให้เผลอหยิบของชิ้นเดิมซ้ำ
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
using namespace std;

int maxItems(int n, int k, int price[])
{
    int dp[1001];

    // initialize
    for(int i=0;i<=k;i++)
        dp[i] = -1;

    dp[0] = 0;

    for(int i=0;i<n;i++) // loop for each item
    {
        for(int j=k;j>=price[i];j--) // loop for each price from k to price[i]
        {
            if(dp[j-price[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j-price[i]] + 1);
            }
        }
    }

    return dp[k];
}

int main()
{
    int n,k;
    cin >> n >> k;

    int price[101];

    for(int i=0;i<n;i++)
        cin >> price[i];

    cout << maxItems(n,k,price);

    return 0;
}
```
</details>

**4. Largest Square of 1's (Dynamic Programming)**
*โจทย์:* กำหนดพื้นที่ขนาด N x M ประกอบด้วยตัวอักษร '#' แทนพื้นที่ที่ใช้งานได้ และ '.' แทนพื้นที่ว่าง จงหาพื้นที่ของสี่เหลี่ยมจัตุรัสขนาดใหญ่ที่สุดที่ประกอบด้วย '#' ทั้งหมด และนับว่ามีสี่เหลี่ยมจัตุรัสขนาดใหญ่ที่สุดนั้นจำนวนกี่รูป (พิมพ์ "ขนาดพื้นที่" และ "จำนวนที่พบ")
*สิ่งที่จะวัด:* การประยุกต์ใช้ DP แบบ 2 มิติ โดยตั้งค่า `dp[i][j]` ให้เก็บความยาวด้านของสี่เหลี่ยมจัตุรัสที่ใหญ่ที่สุดที่จบตรงมุมขวาล่าง `(i, j)` โดยใช้สูตร `dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1`
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == '#') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    if (dp[i][j] > maxSize) {
                        maxSize = dp[i][j];
                    }
                }
            }
        }

        if (maxSize == 0) {
            cout << 0 << " " << 0 << endl;
        } else {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (dp[i][j] == maxSize) {
                        count++;
                    }
                }
            }
            cout << maxSize * maxSize << " " << count << endl;
        }
    }

    return 0;
}
```
</details>

**5. Bounded Coin Change with Coin Tracking**
*โจทย์:* แคชเชียร์ต้องการทอนเงิน $M$ บาท โดยมีเหรียญ $N$ ชนิด แต่ละชนิดมีมูลค่าและจำนวนในลิ้นชักจำกัด จงหา "จำนวนเหรียญรวมที่น้อยที่สุด" ที่ประกอบกันได้พอดียอดทอน พร้อมแจกแจงว่าใช้เหรียญมูลค่าใดบ้าง จำนวนกี่เหรียญ เรียงจากมูลค่ามากไปน้อย หากทอนไม่ได้ให้แสดง `impossible`
*สิ่งที่จะวัด:* การประยุกต์ใช้ DP แบบ Bounded Knapsack (1D array) ควบคู่กับการจำ State (Choice Table `O(N x M)`) เพื่อแกะรอยย้อนหลัง (Backtracking) ว่าใช้เหรียญชนิดไหนไปกี่เหรียญในแต่ละระดับชั้น
<details>
<summary><b>Source Code (Solution)</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Coin {
    int value;
    int count;
};

// Sort coins by value descending
bool compareCoins(const Coin& a, const Coin& b) {
    return a.value > b.value;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Coin> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i].value;
    for (int i = 0; i < n; i++) cin >> coins[i].count;

    int m;
    cin >> m;

    sort(coins.begin(), coins.end(), compareCoins);

    vector<int> dp(m + 1, INF);
    vector<vector<int>> choice(n, vector<int>(m + 1, 0));

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> new_dp = dp;
        int v = coins[i].value;
        int c = coins[i].count;

        for (int j = 0; j <= m; j++) {
            if (dp[j] == INF) continue;
            for (int k = 1; k <= c; k++) {
                long long next_val = (long long)j + (long long)k * v;
                if (next_val > m) break;
                
                if (dp[j] + k < new_dp[next_val]) {
                    new_dp[next_val] = dp[j] + k;
                    choice[i][next_val] = k;
                }
            }
        }
        dp = new_dp;
    }

    if (dp[m] == INF) {
        cout << "impossible\n";
    } else {
        cout << dp[m] << "\n";
        vector<pair<int, int>> result;
        int current_amount = m;
        
        for (int i = n - 1; i >= 0; i--) {
            int k = choice[i][current_amount];
            if (k > 0) {
                result.push_back({coins[i].value, k});
                current_amount -= k * coins[i].value;
            }
        }

        sort(result.begin(), result.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        });

        for (int i = 0; i < result.size(); i++) {
            cout << result[i].first << ":" << result[i].second << "\n";
        }
    }

    return 0;
}
```
</details>
