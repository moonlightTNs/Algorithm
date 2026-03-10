#include<iostream>

using namespace std ; 

int M[INT_MAX] = {0} ;

int F(int n){
	if(n == 0 | n == 1){
		return 1 ;
	}
	else if(M[n] != 0){
		return M[n] ;
	}
	else{
		M[n] = F(n-1) + F(n-2) ;
		return M[n] ;
	}
}


int main(){
	
	int n = 50  ;
	
	F(n) ;
	
}
