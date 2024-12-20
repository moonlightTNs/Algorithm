#include <iostream>
using namespace std;

const int MAX_HOUR = 100000; 

int main() {
    int n;
    cin >> n;
    int timeChanges[MAX_HOUR + 2] = {0}; 

    for (int i = 0; i < n; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        timeChanges[startTime]++;     
        timeChanges[endTime + 1]--;  
    }

    int currentCustomers = 0;  
    int maxCustomers = 0;     
    int peakStartTime = 0;      
    int peakEndTime = 0;      

    for (int i = 0; i <= MAX_HOUR; i++) {
        currentCustomers += timeChanges[i]; 

        if (currentCustomers > maxCustomers) {
            maxCustomers = currentCustomers;
            peakStartTime = i;            
            peakEndTime = i;              
        } else if (currentCustomers == maxCustomers) {
            peakEndTime = i; 
        }
    }

    cout << peakStartTime << " " << peakEndTime << " " << maxCustomers << endl;

    return 0;
}

