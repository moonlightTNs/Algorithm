# HW-9 Graph 2 (Weighted Graph)

## วิธีตีโจทย์ Weighted Graph (Template)

### ขั้นที่ 0: สังเกตว่าต้องใช้ Algorithm อะไร?

| โจทย์ถามอะไร | Algorithm |
|-------------|-----------|
| **Shortest Path** จาก 1 จุด ไปทุกจุด (น้ำหนัก ≥ 0) | **Dijkstra** |
| **Minimum Spanning Tree** (เชื่อมทุก node ด้วย cost น้อยสุด) | **Kruskal** |
| Shortest Path จากหลายจุดพร้อมกัน (Multi-source) | **Dijkstra หลาย source** |

---

### ขั้นที่ 1: Dijkstra — หา Shortest Path

```
หลักการ: กรีดี - เลือก node ที่ dist น้อยสุดก่อนเสมอ

โครงสร้าง:
  dist[]   = ระยะทางสั้นสุดจาก source ถึงแต่ละ node
  pq       = min-heap (priority_queue แบบ min) เก็บ {dist, node}

ขั้นตอน:
  dist[start] = 0, push {0, start} เข้า pq
  while pq ไม่ว่าง:
    pop {d, u} ที่ dist น้อยสุด
    if d > dist[u] → ข้าม (เส้นทางนี้ outdated)
    for each neighbor v ของ u:
      if dist[u] + w < dist[v]:
        อัปเดต dist[v]
        push {dist[v], v} เข้า pq
```

---

### ขั้นที่ 2: Kruskal — หา MST

```
หลักการ: เรียง edge จากน้ำหนักน้อยสุด → เพิ่มเข้า MST ทีละ edge
          ถ้าเพิ่มแล้วเกิด cycle → ข้าม

โครงสร้าง:
  Union-Find (parentSet[]) เพื่อเช็ค cycle

ขั้นตอน:
  ใส่ edge ทุกเส้นเข้า min-heap
  while edgeUsed < n-1:
    pop edge (u, v, w) ที่น้ำหนักน้อยสุด
    if find(u) != find(v):  ← ยังไม่อยู่กลุ่มเดียวกัน = ไม่เกิด cycle
      union(u, v)
      totalWeight += w
      edgeUsed++
```

---

### ขั้นที่ 3: Multi-Source Dijkstra

```
เมื่อมีหลาย source:
  ใส่ทุก source เข้า pq พร้อมกันโดย dist = 0
  Dijkstra ทำงานต่อปกติ
  ผลลัพธ์: dist[v] = ระยะทางจาก source ที่ใกล้ที่สุด ถึง v
```

---

## สรุปทุกไฟล์

---

### 1. MST-Kruskal.cpp
**โจทย์:** กราฟมี n node m edge แต่ละ edge มีน้ำหนัก หา MST แล้วคำนวณ totalWeight - (n-1)

| | |
|--|--|
| **Algorithm** | Kruskal + Union-Find |
| **กราฟ** | Undirected, Weighted |
| **โครงสร้าง** | `priority_queue` (min-heap) เก็บ edge, `parentSet[]` Union-Find |
| **Union-Find** | `find_set(i)` หา root, `union_set(x,y)` รวมกลุ่ม, `is_cycle(u,v)` เช็ค cycle |
| **คำตอบ** | `totalWeight - (n-1)` |

```
เรียง edge น้ำหนักน้อย → มาก (min-heap)
ดึง edge ทีละเส้น:
  ถ้าไม่เกิด cycle → รับเข้า MST
  ถ้าเกิด cycle    → ทิ้ง
จนได้ n-1 เส้น
```

---

### 2. ShortestPath_in_Network.cpp
**โจทย์:** มี C test case แต่ละ case มี n node m edge หา shortest path จาก s ถึง t

| | |
|--|--|
| **Algorithm** | Dijkstra |
| **กราฟ** | Undirected, Weighted |
| **โครงสร้าง** | `vector<vector<pair<int,int>>> adj` (Adjacency List with weight) |
| **min-heap** | `priority_queue<pair<int,int>, ..., greater<>>` เก็บ {dist, node} |
| **คำตอบ** | `dist[t]` (ถ้า INF → -1) |

```
dist[start] = 0
Dijkstra ด้วย min-heap
if dist[u] + weight < dist[v] → อัปเดต dist[v]
return dist[t]
```

---

### 3. Hospital.cpp
**โจทย์:** มีเขต n แห่ง โรงพยาบาลเดิม f แห่ง ต้องการสร้างโรงพยาบาลใหม่ 1 แห่ง เพื่อให้เขตที่ไกลที่สุดใกล้โรงพยาบาลมากที่สุด

| | |
|--|--|
| **Algorithm** | Multi-Source Dijkstra |
| **กราฟ** | Undirected, Weighted |
| **หลักการ** | ลองตั้งโรงพยาบาลใหม่ที่ทุกเขต → Multi-Source Dijkstra (เก่า + ใหม่) → หา maxDist → เลือก candidate ที่ทำให้ maxDist น้อยที่สุด |
| **คำตอบ** | เขตที่ควรตั้งโรงพยาบาลใหม่ |

```
for each candidate (เขตที่ยังไม่มีโรงพยาบาล):
  Multi-Source Dijkstra จากโรงพยาบาลเดิม + candidate
  หา maxDist = max(dist[i]) สำหรับทุก i
  เก็บ candidate ที่ให้ maxDist น้อยสุด
```

---

## สรุปเปรียบเทียบ

| ไฟล์ | Algorithm | กราฟ | ถามอะไร |
|-----|-----------|------|--------|
| MST-Kruskal | Kruskal + Union-Find | Undirected Weighted | MST น้ำหนักรวมน้อยสุด |
| ShortestPath_in_Network | Dijkstra | Undirected Weighted | Shortest path s→t |
| Hospital | Multi-Source Dijkstra | Undirected Weighted | ตำแหน่งโรงพยาบาลใหม่ที่ดีที่สุด |

---

## เปรียบเทียบ Dijkstra vs Kruskal

| | Dijkstra | Kruskal |
|--|----------|---------|
| **เป้าหมาย** | Shortest path จาก 1 จุด | Minimum Spanning Tree |
| **โครงสร้าง** | dist[] + min-heap | Union-Find + min-heap |
| **เลือก** | node ที่ dist น้อยสุด | edge ที่ weight น้อยสุด |
| **เช็ค** | dist ใหม่ < dist เดิม | ไม่เกิด cycle |
