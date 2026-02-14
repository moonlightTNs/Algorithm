#include <iostream>

using namespace std ; 

int V[] = {-1,12,5,4,2} ;
int W[] = {-1,8,7,4,2} ;
int k = 18  ; 
int n = 4 ; 

int MaxV = -99999999 ; 	

void print_sol(int x[], int n) {
	int sum_w = 0 ;
	int sum_v = 0 ; 
	
    for (int i = 1; i <= n; i++) {
//    	cout << x[i] << " ";
        if(x[i] == 1){
        	sum_w += W[i] ;
        	sum_v += V[i] ; 
		}
    }
//    cout << endl;
    
    if(sum_w <= k){ 
    	if( sum_v > MaxV){
    		MaxV = sum_v ; 
		}
	}
}

    
void subset1(int x[], int l, int r ) {
    
    if (l == r) {
           print_sol(x, r);
    } else {
        x[l + 1] = 1;
        subset1(x, l + 1, r);
        x[l + 1] = 0;
        subset1(x, l + 1, r);
    }
}

int main() {
	
	int n = 4 ;
    int x[n + 1];        
    
    subset1(x, 0, n );
    cout << MaxV ; 

    return 0;
}

