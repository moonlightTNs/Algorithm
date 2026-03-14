#include <iostream>
#include <queue>
#include <vector>

using namespace std ;

const int INF = 1e9 ;

// Dijkstra (ใช้ได้เมื่อค่าน้ำหนักของเส้นเชื่อมไม่ติดลบ)
// เป้าหมาย: หาเส้นทางสั้นที่สุดจาก src ไปยังทุกโหนด
vector<int> dijktra(vector<vector<pair<int,int>>> &list , int V , int src){

    // ขั้นที่ 1) Min-heap เรียงตามระยะทาง: {distance, node}
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > pq ;

    // ขั้นที่ 2) อาร์เรย์หลัก
    // dist   = ระยะทางที่ดีที่สุดจาก src ณ ตอนนี้
    // parent = โหนดก่อนหน้าในเส้นทางสั้นที่สุด (ใช้ย้อนเส้นทาง)
    // Intree = โหนดที่ถูกยืนยันระยะทางแน่นอนแล้ว
    vector<int> dist(V,INF) ; 
    vector<int> parent(V, -1) ;
    vector<int> Intree(V,false) ;

    // กำหนดค่าเริ่มต้นให้โหนดต้นทาง

    pq.push({0,src}) ;
    dist[src] = 0 ;

    // ขั้นที่ 3) ประมวลผลโหนดจนกว่า heap จะว่าง

    while(!pq.empty()){
        int currentD = pq.top().first ;
        int currentV = pq.top().second ;
        pq.pop() ;

        // ข้ามข้อมูลเก่าจาก heap หรือโหนดที่ถูกยืนยันแล้ว
        if(Intree[currentV])
            continue ;
        if(currentD > dist[currentV])
            continue ;

        // ยืนยัน currentV: ระยะทางสั้นที่สุดของโหนดนี้ถูกตรึงแล้ว
        Intree[currentV] = true ;

        // ขั้นที่ 4) Relax ทุกเส้นเชื่อมที่ออกจาก currentV (currentV -> v, weight w)
        for(int i =0 ; i < list[currentV].size() ; i++){
            int v = list[currentV][i].first ;
            int w = list[currentV][i].second ;

            if(Intree[v] == false && dist[currentV] + w < dist[v]){
                dist[v] = dist[currentV] + w ;
                pq.push({dist[v] , v}) ;
                parent[v] = currentV ;
            }
        }

    }

    // ขั้นที่ 5) คืนค่าระยะทางสั้นที่สุดจาก src
    return dist ;

}



int main(){

    // อินพุต: จำนวนโหนด N, จำนวนเส้นเชื่อม M, จุดเริ่ม S, จุดหมาย T
    int N,M,S,T ; 
    cin >> N >> M >> S >> T ;

    int U,V,W ;

    vector<vector<pair<int, int>>> list(N+1) ;

    // กราฟถ่วงน้ำหนักแบบไม่มีทิศทาง
    for(int i =0 ; i< M ; i++){
        cin >> U >> V >> W ;
        list[U].push_back({V,W});
        list[V].push_back({U,W}) ;
    }

    vector<int> dist = dijktra(list,N+1,S) ;

    // แสดงระยะทางสั้นที่สุดจาก S ไป T, ถ้าไปไม่ถึงให้แสดง -1
    if(dist[T] == INF)
        cout << -1 ;
    else
        cout << dist[T] ; 

    return 0 ; 
}