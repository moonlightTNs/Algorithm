#include <iostream>
using namespace std;

int arr[100][100] = {} ;

long long C(int n, int k) {
	
	if (k > n)
    return 0;
	
	if (arr[n][k] != 0){
		return arr[n][k] ;
	}
	
    if(k == 0 || n == k ){
    	arr[n][k] = 1;
    	return arr[n][k] ;
	}
	
	return 	arr[n][k] = C(n-1 , k-1) + C(n-1 , k) ;
}

int main() {
    int n, k;
    cin >> n >> k;
    
   cout << C(n,k) ;
    
//    for(int i = 0 ; i < n; i++){
//    	for(int j = 0 ; j<k;j++){
//    		cout << arr[i][j] << " " ;
//    		
// 		}
// 		cout <<endl ;
//	}

    return 0;
}
