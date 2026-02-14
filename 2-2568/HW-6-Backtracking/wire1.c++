#include <iostream>
using namespace std;

int wire[100];      // ความยาวสายไฟแต่ละเส้น
int n;              // จำนวนสายไฟ
int target;         // ความยาวที่ต้องการ
int minCuts;        // จำนวนสายไฟที่ถูกตัดน้อยที่สุด

void print_subset(int x[], int l) {
    cout << "Subset: ";
    for (int i = 1; i <= l; i++)
        cout << wire[x[i]] << " ";
    cout << endl;
}

void subset_index(int x[], int l, int sum) {
    // ตรวจสอบว่าผลรวมเท่ากับ target หรือไม่
    if (sum == target) {
        if (l < minCuts) {
            minCuts = l;
            //print_subset(x, l);  
        }
        return;
    }
    
    // ถ้าผลรวมเกิน target ก็ไม่ต้องค้นหาต่อ
    if (sum > target) return;
    
    int j;
    if (l == 0)
        j = 1;           // start from the 1st element
    else
        j = x[l] + 1;    // continue to next element

    for (int i = j; i <= n; i++) {
        x[l + 1] = i;                       // extend subsets
        subset_index(x, l + 1, sum + wire[i]);   // recursive with new sum
    }
}

int main() {
    cout << "Enter target length: ";
    cin >> target;
    
    cout << "Enter number of wires: ";
    cin >> n;
    
    cout << "Enter wire lengths: ";
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
