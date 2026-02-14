#include <iostream>
using namespace std;

int n;
char books[30];
char result[30];
bool used[30];


int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low ;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++; 
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quicksort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void book(int level) {
    // Base case: ถ้าจัดหนังสือครบ n เล่มแล้ว ให้พิมพ์ผลลัพธ์
    if (level == n) {
        for (int i = 0; i < n; i++) {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    
    // ลองใส่หนังสือแต่ละเล่มในตำแหน่งปัจจุบัน
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            result[level] = books[i];
            book(level + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> books[i];
        used[i] = false;
    }
    
    // Sort หนังสือด้วย Quicksort เพื่อให้ได้ผลลัพธ์เป็น Lexicographic order
    quicksort(books, 0, n - 1);
    
    book(0);
    
    return 0;
}
