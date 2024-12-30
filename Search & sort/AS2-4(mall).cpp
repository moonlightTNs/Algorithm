#include <iostream>
using namespace std;

const int MaxT = 100000;

int main() {
    int n;
    cin >> n;

    
    int timeline[MaxT + 2] = {0};

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        timeline[start]++;
        timeline[end + 1]--;
    }

    
    int max_customers = 0, current_customers = 0;
    int best_start = 0, best_end = 0, temp_start = 0;

    bool in_interval = false; 
    for (int i = 0; i <= MaxT; i++) {
        current_customers += timeline[i];

        if (current_customers > max_customers) {
           
            max_customers = current_customers;
            best_start = i; 
            in_interval = true; 
        } else if (current_customers < max_customers && in_interval) {
           
            best_end = i - 1;
            in_interval = false; 
        }
    }

    cout << best_start << " " << best_end << " " << max_customers << endl;

    return 0;
}
