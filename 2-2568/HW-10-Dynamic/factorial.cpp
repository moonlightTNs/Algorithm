#include<iostream>
using namespace std;

unsigned long long Fac(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n + Fac(n-1);
    }
}

int main(){
    
	unsigned long long  n ;  
	cin >> n ;  

	unsigned long long result = Fac(n) ;
    cout << result << endl;
    

    return 0;
}
