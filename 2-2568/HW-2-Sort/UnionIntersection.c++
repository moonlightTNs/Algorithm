#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[100], B[100];
    bool inA[1001] = {false};  // track ว่าค่าไหนอยู่ใน A
    bool inB[1001] = {false};  // track ว่าค่าไหนอยู่ใน B
    bool used[1001] = {false}; // track ว่าใช้แล้วหรือยัง

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        inA[A[i]] = true;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        inB[B[i]] = true;
    }

    // Intersection: หาตัวที่อยู่ทั้งใน A และ B (ตามลำดับใน A, ไม่ซ้ำ) - O(n)
    int intersection[100], intSize = 0;
    for (int i = 0; i < N; i++) {
        if (inB[A[i]] && !used[A[i]]) {  
            intersection[intSize++] = A[i];
            used[A[i]] = true;
        }
    }

    // Reset used array for union
    for (int i = 0; i < 1001; i++) used[i] = false;

    // Union: เอาทุกตัวใน A ก่อน แล้วเอาตัวใน B ที่ไม่อยู่ใน A - O(n)
    int unionArr[200], uniSize = 0;
    
    // เพิ่มตัวจาก A (ไม่ซ้ำ)
    for (int i = 0; i < N; i++) {
        if (!used[A[i]]) {  
            unionArr[uniSize++] = A[i];
            used[A[i]] = true;
        }
    }
    
    // เพิ่มตัวจาก B ที่ยังไม่อยู่ใน union
    for (int i = 0; i < N; i++) {
        if (!used[B[i]]) {  
            unionArr[uniSize++] = B[i];
            used[B[i]] = true;
        }
    }

    // Print Intersection
    for (int i = 0; i < intSize; i++) {
        cout << intersection[i];
        if (i < intSize - 1) cout << " ";
    }
    cout << endl;

    // Print Union
    for (int i = 0; i < uniSize; i++) {
        cout << unionArr[i];
        if (i < uniSize - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

