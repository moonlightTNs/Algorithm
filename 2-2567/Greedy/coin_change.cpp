#include<bits/stdc++.h>

using namespace std ; 

int coin_change(int A[] , int W , int n){
	
	int i = n-1 ;
	int cnts = 0 ;
	
	while((W > 0) && (i>= 0)){
		int coin = W / A[i] ; // W = target coin
		cnts += coin ; 
		W = W - coin*A[i--] ; // update W 
	}
	
	return cnts ;
}


int main(){
	
	int n = 4 ;
	int A[n] = {1,5,2,10};
	sort(A,A+1) ;
	
	int sum = coin_change(A,13,4);
	cout << "totalcoin" <<" "<<sum ; 
	
	return 0 ; 
}
