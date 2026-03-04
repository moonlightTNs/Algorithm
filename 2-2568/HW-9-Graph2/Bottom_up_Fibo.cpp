#include<iostream>

using namespace std ; 

int M[INT_MAX] = {0} ;

int F(int n){
	int i ;
	int F[INT_MAX] = {0} ;
	F[0] = 1;
	F[1] = 1;
	
	for(int i = 2 ; i<= n; i++){
		F[i] = F[i-1] + f[i-2] ;
	}
	return F[n] ;
}


int main(){
	
	int n = 50  ;
	
	F(n) ;
	
}
