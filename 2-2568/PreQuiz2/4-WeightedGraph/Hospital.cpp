#include <climits>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define INF INT_MAX

// คำนวณ "ระยะทางไกลที่สุด" จากทุกเขต ไปยังโรงพยาบาลที่ใกล้ที่สุด
// เมื่อเราเพิ่มโรงพยาบาลใหม่ที่เขต newHospital
int maxDistanceWithNewHospital(int n,
                               const vector<vector<pair<int, int>>> &roads,
                               const vector<int> &oldHospitals,
                               int newHospital) {
  vector<int> dist(n + 1, INF);

  // priority_queue สำหรับ Dijkstra: {ระยะทาง, เขต}
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // ใส่โรงพยาบาลเดิมทุกแห่งเข้าไปเป็นแหล่งเริ่มต้นระยะทาง 0
  for (int i = 0; i < oldHospitals.size(); i++) {
    dist[oldHospitals[i]] = 0;
    pq.push({0, oldHospitals[i]});
  }

  // ใส่โรงพยาบาลใหม่
  dist[newHospital] = 0;
  pq.push({0, newHospital});

  // Dijkstra: หา shortest path จากโรงพยาบาลที่ใกล้ที่สุด
  while (!pq.empty()) {

    int currentDist = pq.top().first;
    int area = pq.top().second;
    pq.pop();

    if (currentDist > dist[area])
      continue;

    for (int i = 0; i < roads[area].size(); i++) {
      int nextArea = roads[area][i].first;
      int length = roads[area][i].second;

      if (dist[area] + length < dist[nextArea]) {
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

int main() {

  int f, n; // f = จำนวนเขตที่มีโรงพยาบาลเดิม, n = จำนวนเขตทั้งหมด
  cin >> f >> n;

  vector<int> hospitals(f); // รายชื่อเขตที่มีโรงพยาบาลเดิม
  vector<bool> hasHospital(n + 1, false);

  for (int i = 0; i < f; i++) {
    cin >> hospitals[i];
    hasHospital[hospitals[i]] = true;
  }

  // roads[u] = รายการถนนจากเขต u ไปยังเขตอื่น ๆ (ปลายทาง, ระยะทาง)
  vector<vector<pair<int, int>>> roads(n + 1);

  // อ่านถนนทั้งหมด (ตามโจทย์ให้มาจำนวนหนึ่งบรรทัด)
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    roads[x].push_back({y, r});
    roads[y].push_back({x, r});
  }

  int bestLocation = 1;  // เขตที่ควรตั้งโรงพยาบาลใหม่
  int bestMaxDist = INF; // ระยะทางไกลที่สุด (ที่น้อยที่สุดเท่าที่หาได้)

  // ลองตั้งโรงพยาบาลใหม่ที่ทุกเขตที่ยังไม่มีโรงพยาบาลเดิม
  for (int candidate = 1; candidate <= n; candidate++) {

    if (hasHospital[candidate])
      continue; // ข้ามเขตที่มีโรงพยาบาลเดิมแล้ว

    int currentMaxDist =
        maxDistanceWithNewHospital(n, roads, hospitals, candidate);

    // ถ้า candidate นี้ทำให้เขตที่ไกลที่สุดใกล้ลง ก็เลือกตัวนี้
    if (currentMaxDist < bestMaxDist) {
      bestMaxDist = currentMaxDist;
      bestLocation = candidate;
    }
  }

  cout << bestLocation << endl;

  return 0;
}
