#include<iostream>

using namespace std ;

//int binary_search(int a[],int n,int k){
//	int l = 0 , r = (n-1) ; 
//	
//	while(l <= r){
//		int mid = (l+r) / 2 ;
//		if(a[mid] == k){
//			return mid ;
//		}
//		if(a[mid] < k){
//			l = mid +1 ;
//		}
//		else{
//			r = mid -1 ;
//		}
//	}
//	return -1; 
//}


//int re(int a[], int l, int r, int k) {
//    if (l > r) {
//        return -1;
//
//    int mid = l + (r - l) / 2; 
//
//    if (a[mid] == k) {
//        return mid; 
//    } 
//	else if (a[mid] < k) {
//        return re(a, mid + 1, r, k); 
//    } 
//	else {
//        return re(a, l, mid - 1, k); 
//    	}
//	}
//}

void inter(int a[], int l, int r, int k) {
    if (l > r) {
        return ;
	}

    int mid = l + ((k-a[l])*(r-l) / ((a[r])-a[l])) ;
	cout << mid << " " ;    

    if (a[mid] == k) {
        return ; 
    } 
	else if (a[mid] < k) {
        return inter(a, mid + 1, r, k); 
    } 
	else {
        return inter(a, l, mid - 1, k); 
    	}
    	
	}
	



int main() {
    int a[100] = {}; 
    int n = 0 , k = 0 ;
	cin >> n >> k ; 
	
	for(int i=0 ; i<n ; i++){
		cin >> a[i] ;
	}
	
	
    inter(a, 0, n - 1, k)  ; 

    return 0;
}
