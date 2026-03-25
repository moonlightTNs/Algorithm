#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int xi, xj;
};

int main() {
    int n;
    cin >> n;
    vector<Interval> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].xi >> segs[i].xj;
    }
    int xa, xb;
    cin >> xa >> xb;

    // sort by xi, then xj
    sort(segs.begin(), segs.end(), [](const Interval& a, const Interval& b) {
        return a.xi < b.xi || (a.xi == b.xi && a.xj < b.xj);
    });

    vector<Interval> chosen;
    int current = xa;
    int idx = 0;
    while (current < xb) {
        int maxEnd = current;
        int bestIdx = -1;
        // Find the segment that starts before or at current and ends farthest
        while (idx < n && segs[idx].xi <= current) {
            if (segs[idx].xj > maxEnd) {
                maxEnd = segs[idx].xj;
                bestIdx = idx;
            }
            ++idx;
        }
        if (bestIdx == -1) {
            cout << 0 << endl;
            return 0;
        }
        chosen.push_back(segs[bestIdx]);
        current = maxEnd;
    }

    // sort answer by xi, then xj
    sort(chosen.begin(), chosen.end(), [](const Interval& a, const Interval& b) {
        return a.xi < b.xi || (a.xi == b.xi && a.xj < b.xj);
    });

    cout << chosen.size() << endl;
    for (const auto& seg : chosen) {
        cout << seg.xi << " " << seg.xj << endl;
    }
    return 0;
}
