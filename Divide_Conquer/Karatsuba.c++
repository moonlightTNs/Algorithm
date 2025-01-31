#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ฟังก์ชันเติมเลข 0 ด้านหน้าให้ตัวเลขมีความยาวเท่ากัน
string  padZeros(const string &num, int length) {
    string padded = num;
    while (padded.length() < length) {
        padded = "0" + padded;
    }
    return padded;
}

// ฟังก์ชันบวกตัวเลขในรูปแบบสตริง
string addStrings(const string &a, const string &b) {
    int carry = 0;
    string result = "";
    int n = max(a.size(), b.size());
    string aPadded = padZeros(a, n);
    string bPadded = padZeros(b, n);

    for (int i = n - 1; i >= 0; i--) {
        int sum = (aPadded[i] - '0') + (bPadded[i] - '0') + carry;
        result = char((sum % 10) + '0') + result;
        carry = sum / 10;
    }
    if (carry > 0) {
        result = char(carry + '0') + result;
    }
    return result;
}

// ฟังก์ชันลบตัวเลขในรูปแบบสตริง
string subtractStrings(const string &a, const string &b) {
    int n = max(a.size(), b.size());
    string aPadded = padZeros(a, n);
    string bPadded = padZeros(b, n);

    string result = "";
    int borrow = 0;
    for (int i = n - 1; i >= 0; i--) {
        int diff = (aPadded[i] - '0') - (bPadded[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

// ฟังก์ชันคูณด้วย Karatsuba Algorithm
string karatsuba(const string &x, const string &y) {
    int n = max(x.size(), y.size());

    // เติม 0 ให้ความยาวตัวเลขเท่ากัน
    string a = padZeros(x, n);
    string b = padZeros(y, n);

    // Base case: ถ้าความยาวตัวเลขเท่ากับ 1 ให้คูณโดยตรง
    if (n == 1) {
        return to_string((a[0] - '0') * (b[0] - '0'));
    }

    int half = n / 2;

    // แบ่งตัวเลขออกเป็นสองส่วน
    string a1 = a.substr(0, n - half);
    string a2 = a.substr(n - half);
    string b1 = b.substr(0, n - half);
    string b2 = b.substr(n - half);

    // คำนวณส่วนต่าง ๆ
    string A = karatsuba(a1, b1);
    string B = karatsuba(a2, b2);
    string C = karatsuba(addStrings(a1, a2), addStrings(b1, b2));
    string middle = subtractStrings(subtractStrings(C, A), B);

    // รวมผลลัพธ์
    string result = addStrings(
        addStrings(A + string(2 * half, '0'), middle + string(half, '0')), B);

    // ลบ 0 ที่ไม่จำเป็นด้านหน้า
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

int main() {
    string a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    // ทำการเติม 0 ให้ความยาวเท่ากันและเป็นเลขคู่
    int maxLength = max(a.size(), b.size());
    if (maxLength % 2 != 0) {
        maxLength++;
    }
    a = padZeros(a, maxLength);
    b = padZeros(b, maxLength);

    // คำนวณผลลัพธ์ด้วย Karatsuba
    string result = karatsuba(a, b);

    cout << "The product of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
