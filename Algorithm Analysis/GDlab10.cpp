#include <iostream>
using namespace std;

const int MAX_HOUR = 100000; 

int main() {
    int NumCT;
    cin >> NumCT;

    int timeChanges[MAX_HOUR + 2] = {0}; 

    
    for (int i = 0; i < NumCT; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        timeChanges[startTime]++;     
        timeChanges[endTime + 1]--;  
    }

   
    int currentCustomers = 0;  
    int maxCustomers = 0;     
    int peakStartTime = 0;      
    int peakEndTime = 0;      

    for (int hour = 0; hour <= MAX_HOUR; hour++) {
        currentCustomers += timeChanges[hour]; 

        if (currentCustomers > maxCustomers) {
            maxCustomers = currentCustomers;
            peakStartTime = hour;            
            peakEndTime = hour;              
        } else if (currentCustomers == maxCustomers) {
            peakEndTime = hour; 
        }
    }

    
    cout << peakStartTime << " " << peakEndTime << " " << maxCustomers << endl;

    return 0;
}

