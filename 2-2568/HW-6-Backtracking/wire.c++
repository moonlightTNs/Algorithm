#include <iostream>
using namespace std ;

int _min = INT_MAX ;
int sol[100];      // เก็บ index สายไฟที่เลือก (คำตอบที่ดีที่สุด)
int current[100];  // เก็บ index สายไฟที่กำลังลอง

void subset_index(int total, int x[], int idx, int L, int n) {
    // Base case: ได้ความยาวพอดี
    if(total == L) {
        if(idx < _min) {
            _min = idx;
            // เก็บคำตอบ
            for(int i = 0; i < idx; i++) {
                sol[i] = current[i];
            }
        }
        return;
    }
    
    // Pruning: ถ้าเกินแล้วไม่ต้องลองต่อ
    if(total > L) return;
    
    // ลองเลือกสายไฟแต่ละขนาด
    for(int i = 0; i < n; i++) {
        current[idx] = i;  // เก็บ index ที่เลือก
        subset_index(total + x[i], x, idx + 1, L, n);
    }
}

int main() {
	int L = 0 ; 
	int n = 0;
	cin >> L >> n ;
    int x[n+1];
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] ;
	}	
	 
    subset_index(0, x, 0, L, n);
 
	cout << _min << endl;
	
	// แสดงสายไฟที่เลือก
	cout << "สายไฟที่เลือก: ";
	for(int i = 0; i < _min; i++) {
	    cout << x[sol[i]];
	    if(i < _min - 1) cout << " + ";
	}
	cout << " = " << L << endl;
	
    return 0;
}