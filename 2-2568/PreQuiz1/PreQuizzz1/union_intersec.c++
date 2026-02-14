#include <iostream>
using namespace std;

int main() {
    int a[] = {6, 8, 7, 4, 1};
    int b[] = {3, 2, 7, 1, 2};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    // Map สำหรับเก็บว่าค่าไหนอยู่ใน array ไหนบ้าง
    int inA[1000] = {0};
    int inUnion[1000] = {0};
    int inInter[1000] = {0};

    // Union และ Intersection arrays
    int unionArr[1000], interArr[1000];
    int unionSize = 0, interSize = 0;

    // เพิ่มสมาชิกจาก a เข้า union
    for (int i = 0; i < n1; i++) {
        inA[a[i]] = 1;
        if (inUnion[a[i]] == 0) {
            inUnion[a[i]] = 1;
            unionArr[unionSize++] = a[i];
        }
    }

    // ตรวจสอบสมาชิกจาก b
    for (int i = 0; i < n2; i++) {
        // ถ้าอยู่ใน a ด้วย -> intersection (ไม่ซ้ำ)
        if (inA[b[i]] == 1 && inInter[b[i]] == 0) {
            inInter[b[i]] = 1;
            interArr[interSize++] = b[i];
        }
        // เพิ่มเข้า union (ถ้ายังไม่มี)
        if (inUnion[b[i]] == 0) {
            inUnion[b[i]] = 1;
            unionArr[unionSize++] = b[i];
        }
    }

    // แสดงผล Union
    cout << "Union: ";
    for (int i = 0; i < unionSize; i++) {
        cout << unionArr[i] << " ";
    }
    cout << endl;

    // แสดงผล Intersection
    cout << "Intersection: ";
    for (int i = 0; i < interSize; i++) {
        cout << interArr[i] << " ";
    }
    cout << endl;

    return 0;
}