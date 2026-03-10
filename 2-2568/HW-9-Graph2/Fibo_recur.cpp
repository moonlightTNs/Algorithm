#include<iostream>
using namespace std;

unsigned long long F(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return F(n-1) + F(n-2);
    }
}

int main(){
    
	unsigned long long  n ;  
	cin >> n ;  

	unsigned long long result = F(n) ;
    cout << result << endl;
    

    return 0;
}
