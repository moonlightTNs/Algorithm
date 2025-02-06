#include <iostream>
using namespace std ;



//void print_sol(int x[], int n) {
//
//    for (int i = 1; i <= n; i++) {
//        cout << x[i];
//    }
//
//    printf("\n");
//}
int _min = 99999 ;

void subset2(int total,int x[], int count , int L , int n) {

	if(total == L){
		if(count < _min){
			_min  = count ; 
		}
		return ; 
	}
	if(total > L) return ; 

    for (int i = 0; i < n; i++) {
        subset2(total + x[i], x, count + 1 , L , n);
    }
}

int main() {
	int L = 0 ; 
	int n =0;
	cin >> L >> n ;
int x[n+1];
	
	for(int i =0 ; i<n ; i++){
		cin >> x[i] ;
	}	
	 
    subset2(0, x,0,L,n);
 
	cout << _min << endl ; 
    return 0;
}
