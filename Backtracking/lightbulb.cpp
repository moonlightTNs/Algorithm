#include <iostream>
using namespace std  ; 
int count = 0; 
void print_sol(int x[], int n) {
	count = count +1 ;
//    for (int i = 1; i <= n; i++) {
//        cout << x[i] ; 
//    }
//   cout << endl ;
}

void subset1(int x[], int l, int r , int sum,int h) {
    if(sum == h){
    	
    	print_sol(x, r);
    	
    	return ;
	}
	
	if (l == r) {
    	return ; 
    } 
	if(sum > h){
		return ;
	}
    	    x[l + 1] = 1;
		sum = sum +1 ;
        subset1(x, l + 1, r, sum, h);
        x[l + 1] = 0;
        sum = sum -1 ;
        subset1(x, l + 1, r, sum,h)	;
    
}

int main() {
    int n = 0 ;           
    int h = 0 ;
    cin >> n >> h ; 
    
	int sum = 0 ; 
	int x[n + 1];       
    subset1(x, 0, n,sum,h);
    cout << count ;

    return 0;
}
