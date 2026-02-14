#include<iostream>

using namespace std ; 


void printsol(int x[] ,int a[] , int n , int target){
	int sum = 0 ;
	for(int i = 1; i <= n ; i++){
		if(x[i] == 1) sum = sum + a[i]; 
	}
	if(sum == target){
		for(int i = 1 ; i<=n ; i++){
			 if(x[i] == 1) {
			 	cout << a[i] << " " ;
			 } 
			
		}
		cout << endl ;
		cout << "sum : " << sum ;
	}
	 
}

void subset(int x[] ,int a[] , int l , int r , int k ){
	if(l == r){
		printsol(x,a,r,k) ; 
	}
	else{
		x[l+1] = 1 ;
		subset(x,a,l+1,r,k) ;
		x[l+1] = 0 ;
		subset(x,a,l+1,r,k) ;
	}
}


int main(){
	int n = 5 ;
	int a[] = {0,25,10,9,2,1} ;
	int x[6] ;
	int sumk = 12 ;
	subset(x,a,0,n,sumk) ;
	return 0 ;

}
