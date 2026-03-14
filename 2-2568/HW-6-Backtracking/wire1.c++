#include <iostream>
using namespace std;

int wire[100];      // ความยาวสายไฟแต่ละเส้น
int n;              // จำนวนสายไฟ
int target;         // ความยาวที่ต้องการ
int minCuts;        // จำนวนสายไฟที่ถูกตัดน้อยที่สุด

// void print_subset(int x[], int l) {
//     cout << "Subset: ";
//     for (int i = 1; i <= l; i++)
//         cout << wire[x[i]] << " ";
//     cout << endl;
// }

void subset_index(int selectedIndex[], int chosenCount, int currentSum) {
    // Base case: ถ้าผลรวมได้พอดี target ให้พยายามอัปเดตคำตอบที่ดีที่สุด
    if (currentSum == target) {
        if (chosenCount < minCuts) {
            minCuts = chosenCount;
            //print_subset(selectedIndex, chosenCount);
        }
        return;
    }

    // Pruning: ถ้าผลรวมเกินแล้ว หรือใช้จำนวนเส้นไม่น้อยกว่า best เดิม ก็หยุดกิ่งนี้
    if (currentSum > target || chosenCount >= minCuts)
        return;

    int startIndex;
    if (chosenCount == 0)
        startIndex = 1;                    // เริ่มจากเส้นแรก
    else
        startIndex = selectedIndex[chosenCount] + 1; // ต่อจากเส้นล่าสุดที่เลือก

    // เลือกเส้นถัดไปโดยบังคับ index เพิ่มขึ้น -> ไม่ซ้ำเส้นเดิม/ไม่ซ้ำลำดับ
    for (int i = startIndex; i <= n; i++) {
        selectedIndex[chosenCount + 1] = i;
        subset_index(selectedIndex, chosenCount + 1, currentSum + wire[i]);
    }
}

int main() {

    cin >> target;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> wire[i];
    }
    
    minCuts = n + 1;     // เริ่มต้นด้วยค่าที่เป็นไปไม่ได้
    int x[n + 1];        // Array to store subset indices
    subset_index(x, 0, 0);
    
    if (minCuts == n + 1)
        cout << "No solution found" << endl;
    else
        cout << minCuts << endl;
    
    return 0;
}
