#include <iostream>
using namespace std;

long long C(int n, int k) {
	if (k > n)
    return 0;
	
	int arr[n+1][k+1] = {};
    for(int i = 0 ; i <=n; i++){
    	for(int j = 0 ; j<=k;j++){
    		if (j == 0) arr[i][j] = 1;
    		else if (i == j) arr[i][j] = 1;
 		}
	}
	
	for(int i = 0 ; i <=n; i++){
    	for(int j = 0 ; j<=k;j++){
    		arr[i][j] = arr[i-1][j-1] + arr[i-1][j] ;
			
 		}
	}
	
	return arr[n][k] ;

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
