# สรุปขั้นตอนการทำพื้นฐานของแต่ละเรื่อง (Algorithm Topics Summary)

เอกสารนี้รวบรวมสรุปขั้นตอนการทำพื้นฐานสำหรับแต่ละเรื่องในเนื้อหาวิชา Algorithm (อ้างอิงจาก HW-6 ถึง HW-10)

---

## 1. Backtracking (HW-6)
การใช้ Backtracking เหมาะกับปัญหาการค้นหา (Search) รูปแบบผสมผสาน (Combinatorial) หรือปัญหาการจัดเรียง (Permutation/Subset) ที่ต้องหาคำตอบ "ทั้งหมด" หรือคำตอบที่มี "เงื่อนไขเฉพาะ"

**ขั้นตอนการทำพื้นฐาน:**
1. **กำหนดลักษณะ State:** กำหนดอาร์เรย์เก็บผลลัพธ์ย่อย (เช่น `x[1..n]`) หรืออาร์กิวเมนต์ที่คอยส่งต่อไปในแต่ละระดับชั้นกิ่งก้าน (Level/Depth)
2. **หาจุดยุติ (Base Case):** เมื่อจำนวนระดับ หรือจำนวนตัวแปรครบตามเป้า (เช่น `start == end`) ให้นำผลลัพธ์ย่อยนั้นมาประมวลผล (ปริ้นท์ออก ตรวจสอบ หรือบวกตัวนับ)
3. **กำหนดรูปแบบการแตกกิ่ง (Recursive Call):**
   - **Subset:** สร้างกิ่งตัวเลือกเป็น "เอา" (`x[i] = 1`) หรือ "ไม่เอา" (`x[i] = 0`)
   - **Permutation:** สลับตำแหน่ง (Swap) ค่าตัวแปรในอาร์เรย์ จากจุดหมุนถึงจุดท้าย แล้วจึงสลับกลับเพื่อคืนค่ากลับมา (Backtrack)
4. **ใส่เงื่อนไข (Pruning/Bounding):** ก่อนหรือหลังทำการแตกกิ่ง ให้เช็คความถูกต้อง (เช่น การตรวจสอบของ N-Queens ว่าแนวทแยงชนกันหรือไม่, ตัวเลขที่ติดกันเกินกรอบไหม) ถ้าผิดให้หยุดแล้วตัดกิ่งทิ้งทันทีไม่ต้องไปต่อ

**Source Code สำหรับหัวข้อนี้:** 
- [permution_nqueens.c++](./1-Backtracking/permution_nqueens.c++)
- [permutation.cpp](./1-Backtracking/permutation.cpp)
- [knapsack.cpp](./1-Backtracking/knapsack.cpp)
---

## 2. Greedy Algorithm (HW-7)
Greedy เป็นวิธีการเลือกทางที่ดีที่สุดในปัจจุบัน (Local Optimum) โดยหวังว่าสุดท้ายจะได้คำตอบที่ดีที่สุดโดยรวมเสมอ เหมาะกับปัญหาเกี่ยวกับการจัดตารางเวลา, Fractional Knapsack

**ขั้นตอนการทำพื้นฐาน:**
1. **พิจารณาเกณฑ์ (Heuristic):** หาสิ่งชี้วัดความคุ้มค่า เช่น ในปัญหา Fractional Knapsack ให้คิดสัดส่วน "มูลค่าต่อน้ำหนัก" (Ratio) หรือในปัญหาการจัดการแพลตฟอร์มให้ดูเวลามาถึง (Arrival time) เป็นต้น
2. **การเรียงลำดับ (Sorting):** ใช้เกณฑ์ที่หามาได้ มาจัดเรียงข้อมูลชุดเดิม (มักใช้ Quick Sort หรือ Sort Library)
3. **การหยิบข้อมูล (Selection/Iteration):** เดินจากของที่คุ้มที่สุดหรือตามลำดับที่เรียงไว้:
   - ตรวจเงื่อนไขว่าหยิบได้ไหม? (เช่น น้ำหนักในกระเป๋าเหลือไหม)
   - อัปเดตทรัพยากรที่เหลือกับค่าผลลัพธ์สะสม (Total Value)
   - หากโจทย์เป็นแบบ Fractional สามารถแตกย่อยของชิ้นสุดท้ายบางส่วนเพื่อให้พอดีตามเงื่อนไข (คำนวณสัดส่วน ratio)

**Source Code สำหรับหัวข้อนี้:** 
- [fractional_knapsack.cpp](./2-Greedy/fractional_knapsack.cpp)
- [min_platforms.cpp](./2-Greedy/min_platforms.cpp)
---

## 3. Graph Traversal (HW-8)
ใช้ค้นหาและท่องไปในกราฟว่าใครเชื่อมถึงใคร ระยะห่างขั้นต่ำที่สุด (โดยจำนวนเส้นเชื่อม) เหมาะกับปัญหา Flood Fill, Unreachable Node, Path Existence

**ขั้นตอนการทำพื้นฐาน:**
1. **สังเกตลักษะกราฟ:** กราฟเป็นแบบมีทิศทาง (Directed) หรือไม่มีรอบ (Undirected)?
2. **เลือกใช้ Algorithm:** 
   - **BFS (Breadth-First Search):** เหมาะสำหรับหาระยะสั้นสุดแบบไม่มี Weight หรือกวาดพื้นที่รอบๆ (อาศัย Queue เป็นโครงสร้างข้อมูลหลัก)
   - **DFS (Depth-First Search):** เหมาะสำหรับขุดลึกไปจนสุดทาง ใช้เช็คว่าสุดทางมีวัฎจักรหรือทดสอบการเข้าถึงจุด (อาศัย Stack หรือ Recursion เป็นหลัก)
3. **จัดการ Structure:**
   - เตรียมตัวแปร `visited` หรือ `dist` ให้มีขนาดเท่าจำนวน Node เพื่อใช้เก็บว่าไปมาหรือยัง (Base initialization เช่น `visited = false`, `dist = -1`)
4. **เดินกราฟ:**
   - แบบ BFS: `push` ค่าเริ่มเข้า Queue, ขณะ Loop ไม่ว่างให้ `pop` และกวาดสมาชิกบ้านใกล้เรือนเคียงทุกตัวที่ `visited == false` เข้า Queue 
   - แบบ DFS: เรียกตัวเองผ่าน Recursion หากเจอ Node เพื่อนบ้านที่ยัง `visited == false`

**Source Code สำหรับหัวข้อนี้:** 
- [FloodFill.cpp](./3-GraphTraversal/FloodFill.cpp)
- [BFSwithDepthLimit.cpp](./3-GraphTraversal/BFSwithDepthLimit.cpp)
---

## 4. Weighted Graph & Minimum Spanning Tree (HW-9)
กราฟคราวนี้เส้นเชื่อมมี "น้ำหนัก" (Cost/Weight) ทำให้การค้นหาต้องคำนึงถึงค่าน้ำหนักเหล่านี้

**ขั้นตอนการทำพื้นฐาน:**
1. **การหา Shortest Path (Dijkstra's Algorithm):**
   - เตรียบ Array ระยะทาง `dist` โดยตั้งค่าจุดเริ่มต้น `dist[start] = 0` นอกนั้นให้เป็น `INF`
   - ใช้ `priority_queue` แบบ Min-Heap เก็บ `{distance, node}`
   - ดึง Node ที่ระยะทางสั้นสุดมาคำนวณเพื่อนบ้าน `if (dist[u] + weight < dist[v])` ให้ปรับใหม่แล้วยัดลงคิวต่อไป
2. **การหา Minimum Spanning Tree (Kruskal's Algorithm):**
   - รวบรวม Edge ทั้งหมดโยนลง Array แล้วจัดเรียง (หรือใช้ Min-Heap) ตามน้ำหนักจากน้อยไปมาก
   - นำ Edge ที่เบาสุดออกมาต่อกันทีละเส้น โดยใช้โครงสร้างข้อมูล **Union-Find** เช็คก่อนถ้าหัวท้าย Edge นั้นไม่อยู่ในเซตเดียวกัน (`Find(u) != Find(v)`) จึงนำมารวมกลุ่ม (`Union(u, v)`)
   - ทำไปเรื่อยๆ จนกว่าจะได้จำนานเส้นเชื่อมเป็น $V-1$

**Source Code สำหรับหัวข้อนี้:** 
- [MST-Kruskal.cpp](./4-WeightedGraph/MST-Kruskal.cpp)
- [Hospital.cpp](./4-WeightedGraph/Hospital.cpp)
- [Postman.cpp](./4-WeightedGraph/Postman.cpp)
---

## 5. Dynamic Programming (HW-10)
DP เป็นเทคนิคการนำปัญหาย่อยที่ได้คำตอบแล้วมาจดจำและเรียกใช้ (Memoization/Tabulation) เพื่อหลีกเลี่ยงการคำนวณซ้ำ ช่วยให้ปัญหา Combinatoric ลดเวลาลงอย่างมหาศาล

**ขั้นตอนการทำพื้นฐาน:**
1. **กำหนด State (นิยามของ `dp[]`):** ตัวแปร `dp[i]` หรือ `dp[i][j]` หมายถึงอะไร (เช่น `dp[i]` คือจำนวนวิธีในการจ่ายผลรวมเหรียญเท่ากับ `i`)
2. **หา Base Case:** จุดย่อยสุดที่รู้คำตอบแน่ๆ โดยไม่ต้องผ่านการคำนวณ (เช่น `dp[0] = 1`)
3. **หาสูตรการเปลี่ยนสถานะ (Recurrence Relation):** หรือเรียกว่า Transition Formula มองให้ออกว่า `dp[i]` จะมาจาก `dp[i-1]`, `dp[i-2]` มารวมกันได้อย่างไร? (เช่นการหาจำนวนวิธี หรือรวม Max Profits)
4. **กำหนดลำดับการทำ (Loop Direction หรือ Bottom-Up vs Top-Down):** 
   - **Bottom-Up:** วนลูปจากสิ่งที่เล็กที่สุดไปจนถึงเป้าหมาย 
   - **Top-Down:** ใช้ตัวแปรจดผ่าน Recursion แล้วย้อนเป้าหมายกลับไปสู่เคสฐาน
5. **ดึงผลลัพธ์ที่เป็นคำตอบ:** ดูจากเป้าหมายโจทย์ว่าอยู่ตำแหน่งใด (เช่น `dp[n]`)

**Source Code สำหรับหัวข้อนี้:** 
- [Coin-Change-Problem.c++](./5-DynamicProgramming/Coin-Change-Problem.c++)
- [Minimum_Path_Matrix.c++](./5-DynamicProgramming/Minimum_Path_Matrix.c++)
- [KnapsackMaxitems.c++](./5-DynamicProgramming/KnapsackMaxitems.c++)
- [Storm.cpp](./5-DynamicProgramming/Storm.cpp)
- [Largest_Square.cpp](./5-DynamicProgramming/Largest_Square.cpp)
- [Bounded_Coin_Change.cpp](./5-DynamicProgramming/Bounded_Coin_Change.cpp)
