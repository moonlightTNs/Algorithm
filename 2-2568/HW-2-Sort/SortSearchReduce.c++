#include <iostream>
using namespace std;

const int MAXN = 20000;
const int MAXS = MAXN * 12 + 10;

int a[MAXN];
char s[MAXS];

// Selection Sort 
void selectionSort(int arr[], int n) {
    int i , j ,min , temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // swap arr[i] and arr[min]
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void appendNumber(char s[], int &len, int x) {
    if (x == 0) { s[len++] = '0'; return; }

    char tmp[12];
    int tlen = 0;

    while (x > 0) {
        tmp[tlen++] = char('0' + (x % 10));
        x /= 10;
    }
    for (int i = tlen - 1; i >= 0; i--) s[len++] = tmp[i];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // อ่านตัวเลขเข้า array จนจบบรรทัด
    // int cnt = 0;
    // int x;
    // while (cin >> x) {
    //     a[cnt++] = x;
    //     // เช็คว่าถึงจบบรรทัดหรือยัง
    //     while (cin.peek() == ' ') cin.get(); // ข้าม space
    //     if (cin.peek() == '\n' || cin.peek() == EOF) break;
    // }

    // if (cnt == 0) return 0;

    // 1) sort
    selectionSort(a, n);

    // 2) ต่อเลขเป็นสตริง
    int len = 0;
    for (int i = 0; i < n; i++) appendNumber(s, len, a[i]);

    // Output บรรทัด 1
    for (int i = 0; i < len; i++) cout << s[i];
    cout << "\n";

    // 3) หาเลขโดดที่ซ้ำติดกันมากที่สุด
    int maxLen[10];  // เก็บความยาวสูงสุดของการซ้ำติดกันของแต่ละ digit
    for (int d = 0; d < 10; d++) maxLen[d] = 0;

    int idx = 0;
    while (idx < len) {
        char c = s[idx];
        int count = 1;
        while (idx + count < len && s[idx + count] == c) count++;
        int digit = c - '0';
        if (count > maxLen[digit]) maxLen[digit] = count;
        idx += count;
    }

    // หาค่าความยาวสูงสุด
    int globalMax = 0;
    for (int d = 0; d < 10; d++) {
        if (maxLen[d] > globalMax) globalMax = maxLen[d];
    }

    // Output บรรทัด 2 (digit ที่มีความยาวซ้ำสูงสุด เรียง 0..9)
    bool first = true;
    for (int d = 0; d < 10; d++) {
        if (maxLen[d] == globalMax && globalMax > 1) {
            if (!first) cout << " ";
            cout << d;
            first = false;
        }
    }
    cout << "\n";

    // 4) reduce: ยุบตัวซ้ำติดกันให้เหลือ 1 ตัว
    cout << s[0];
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i - 1]) cout << s[i];
    }
    cout << "\n";

    return 0;
}
