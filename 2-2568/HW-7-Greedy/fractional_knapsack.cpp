#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item {
 public:
  int idx;
  double weight;
  double value;
  double ratio;
};

double fractionalKnapsack(const vector<Item> &items, double W,
                         vector<double> &fraction) {
  double remaining = W;
  double totalValue = 0.0;

  for (int i = 0; i < (int)items.size(); i++) {
    if (remaining <= 0) {
      break;
    }

    int idx = items[i].idx;
    if (items[i].weight <= remaining) {
      fraction[idx] = 1.0;
      totalValue += items[i].value;
      remaining -= items[i].weight;
    } else {
      double frac = remaining / items[i].weight;
      fraction[idx] = frac;
      totalValue += items[i].value * frac;
      remaining = 0;
    }
  }

  return totalValue;
}

int main() {
  int n;
  double W;
  cin >> n >> W;

  vector<Item> items(n);
  vector<double> fraction(n, 0.0);

  // รับ input น้ำหนักและมูลค่า
  for (int i = 0; i < n; i++)
    cin >> items[i].weight;
  for (int i = 0; i < n; i++)
    cin >> items[i].value;

  // คำนวณ ratio และเก็บ index เดิม
  for (int i = 0; i < n; i++) {
    items[i].idx = i;
    items[i].ratio = items[i].value / items[i].weight;
  }

  sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
    if (a.ratio == b.ratio) {
      return a.idx < b.idx;
    }
    return a.ratio > b.ratio;
  });

  double totalValue = fractionalKnapsack(items, W, fraction);

  // แสดงสัดส่วนการเลือก item ตามลำดับเดิม (ทศนิยม 2 ตำแหน่ง)
  cout << fixed;
  cout.precision(2);
  for (int i = 0; i < n; i++) {
    cout << fraction[i] << " ";
  }
  cout << endl;

  // แสดงมูลค่ารวมสูงสุด
  cout << totalValue << endl;

  return 0;
}
