#include <iostream>

using namespace std;

// ฟังก์ชันสำหรับเรียงลำดับแบบมากไปน้อย
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                // สลับค่า
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// ฟังก์ชันสำหรับคำนวณผลรวมของ k ค่าแรก
double sumOfTopK(int arr[], int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // เรียงลำดับจากมากไปน้อย
    sortDescending(arr, n);

    // คำนวณผลรวมของ k ค่าแรก
    double sum = sumOfTopK(arr, k);

    // แสดงผลเฉลี่ยด้วยทศนิยม 2 ตำแหน่ง
    printf("%.2f\n", sum / k);

    return 0;
}
