# HW-8 Graph

## วิธีตีโจทย์ Graph (Template)

### ขั้นที่ 0: สังเกตว่าโจทย์นี้เป็น Graph ไหม?
- มี **node (จุด)** และ **edge (เส้นเชื่อม)** ระหว่างกัน
- ถามเรื่องการเดินทาง / ความเชื่อมต่อ / ระยะทาง / การเข้าถึง

---

### ขั้นที่ 1: กราฟนี้เป็นแบบไหน?

| ประเภท | ความหมาย | โครงสร้างเก็บ |
|--------|---------|--------------|
| **Undirected** | เส้นสองทิศทาง | `adj[u].push_back(v)` และ `adj[v].push_back(u)` |
| **Directed** | เส้นทิศทางเดียว | `adj[u].push_back(v)` เท่านั้น |
| **Weighted** | แต่ละเส้นมีน้ำหนัก | `adj[u].push_back({v, w})` |

---

### ขั้นที่ 2: เลือก Algorithm ให้ถูก

| โจทย์ถามอะไร | ใช้ Algorithm |
|-------------|-------------|
| เยี่ยมทุก node / ตรวจ reachable | **DFS** |
| ระยะทางสั้นสุด (ไม่มีน้ำหนัก) | **BFS** |
| ระยะทางสั้นสุด (มีน้ำหนัก) | **Dijkstra** |
| Minimum Spanning Tree | **Kruskal / Prim** |
| นับพื้นที่ที่เชื่อมกัน (2D grid) | **Flood Fill (BFS/DFS)** |

---

### ขั้นที่ 3: เตรียม visited[] / dist[]
```
BFS/DFS:   vector<bool> visited(V+1, false)
BFS dist:  vector<int>  dist(V+1, -1)        ← -1 = ยังไม่ไป
Dijkstra:  vector<int>  dist(n, INF)          ← INF = ยังไม่รู้
```

---

### ขั้นที่ 4: โครงสร้าง BFS vs DFS

```
BFS (ใช้ queue):          DFS (ใช้ recursion):
push start node           call DFS(start)
while queue not empty:    mark visited
  pop current             for each neighbor:
  for each neighbor:        if not visited:
    if not visited:           DFS(neighbor)
      push neighbor
      mark visited
```

---

## สรุปทุกไฟล์

---

### 1. BFSwithDepthLimit.cpp
**โจทย์:** กราฟ directed มี V node เริ่มจาก node k ทำ BFS ได้ลึกสุด m ระดับ นับว่ามีกี่ node ที่ไม่ถูกครอบคลุม

| | |
|--|--|
| **Algorithm** | BFS with Depth Limit |
| **กราฟ** | Directed, Unweighted |
| **โครงสร้าง** | `vector<vector<int>> graph` (Adjacency List) |
| **หลักการ** | BFS ปกติ แต่ถ้า `dist[current] == m` → หยุดขยายต่อ |
| **คำตอบ** | นับ node ที่ `dist[i] == -1` หรือ `dist[i] > m` |

```
dist[start] = 0
BFS วนปกติ แต่ if dist[current] == m → continue (ไม่ขยาย)
นับ node ที่ยังไม่ถูก visit
```

---

### 2. directedVunreachable.cpp
**โจทย์:** กราฟ directed กำหนด start node หลายตัว สำหรับแต่ละ start ให้แสดง node ที่ไม่สามารถเข้าถึงได้

| | |
|--|--|
| **Algorithm** | DFS |
| **กราฟ** | Directed, Unweighted |
| **โครงสร้าง** | `vector<vector<int>> adjacencyList` |
| **หลักการ** | DFS จาก start → mark visited → แสดง node ที่ยัง `visited[v] == false` |
| **คำตอบ** | node ที่ไม่ถูก visit = unreachable |

```
for each startNode:
  DFS(startNode, visited)
  print v ที่ visited[v] == false
```

---

### 3. FloodFill.cpp
**โจทย์:** กำหนด grid ตัวอักษร N×M และจุด (X,Y) นับจำนวน cell ที่มีสีเดียวกันและเชื่อมต่อกัน (4 ทิศ)

| | |
|--|--|
| **Algorithm** | BFS (Flood Fill) |
| **กราฟ** | 2D Grid (Implicit Graph) |
| **โครงสร้าง** | `vector<string> image` |
| **หลักการ** | BFS ขยายไป 4 ทิศ เฉพาะ cell ที่มีสีเดียวกับ start |
| **คำตอบ** | นับจำนวน cell ที่ถูก visit |

```
dx[] = {-1,1,0,0}   dy[] = {0,0,-1,1}
BFS ขยายเฉพาะ cell ที่ image[nx][ny] == originalColor
นับ count ทุกครั้งที่ pop
```

---

### 4. undirectedShortest.cpp
**โจทย์:** กราฟ undirected หา shortest path (จำนวน edge น้อยสุด) จาก start ถึง destination

| | |
|--|--|
| **Algorithm** | BFS |
| **กราฟ** | Undirected, Unweighted |
| **โครงสร้าง** | `vector<vector<int>> list` (Adjacency List) |
| **หลักการ** | BFS ให้ระยะทางสั้นที่สุด เพราะขยาย level ต่อ level |
| **คำตอบ** | `dist[destination]` |

```
dist[start] = 0
BFS → dist[neighbor] = dist[current] + 1
return dist[dest]
```

---

## สรุปเปรียบเทียบ

| ไฟล์ | Algorithm | กราฟ | ถามอะไร |
|-----|-----------|------|--------|
| BFSwithDepthLimit | BFS | Directed | node นอก depth m |
| directedVunreachable | DFS | Directed | node ที่เข้าไม่ถึง |
| FloodFill | BFS | 2D Grid | พื้นที่สีเดียวกัน |
| undirectedShortest | BFS | Undirected | จำนวน edge น้อยสุด |
