#include <iostream>
using namespace std;

int countBits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 2) + countBits(n / 2); // ตรวจสอบบิตสุดท้ายและเรียกตัวเอง
}

int main()
{
    int n;
    cin >> n;

    if (n < 0 || n > 500)
    {
        return 1;
    }

    int result = countBits(n);
    cout << result << endl;

    return 0;
}
