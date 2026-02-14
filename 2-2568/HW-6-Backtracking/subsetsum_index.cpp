#include<iostream>
using namespace std ; 

void printsol(int x[] ,int a[] , int l ) {
	for(int i=1 ; i<=l ; i++){
//		cout << a[x[i]] << " " ;
//		cout << endl ;
		cout << x[i] << " " ;
	}
	 cout << endl ;
}

void subset2(int x[] ,int a[],int l , int n ,int current_sum ,int target) {
		
	if(current_sum == target){
		printsol(x,a,l) ;
		cout << "current_sum " << current_sum ;   
		cout << endl ; 
		cout << "target " << target ; 
		cout << endl ; 
	}
	
	int j ; 
	if(l == 0) {
		j = 1 ;
	}
	else{
		j = x[l] + 1 ; 	
	} 
	
	for(int i=j;i<=n;i++){
		x[l+1] = i ;
		subset2(x,a,l+1,n,current_sum + a[i],target) ; 
	}
}





int main(){
	int n = 4 ;
	int a[] = {0,25,10,9,2} ;
	int x[n+1] ;
	int sumk = 36 ;
	subset2(x,a,0,n,0,sumk) ;
	return 0 ;

}
