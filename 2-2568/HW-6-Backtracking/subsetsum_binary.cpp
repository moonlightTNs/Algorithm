#include<iostream>

using namespace std ; 

void binary(int x[] ,int a[] , int idx , int n , int current_sum , int target ){
	if(current_sum > target){
		return;
	}

	if(idx > n){
		if(current_sum == target){
			for(int i = 1 ; i <= n ; i++){
				if(x[i] == 1) {
					cout << a[i] << " ";
				}
			}
			cout << endl;
			cout << "sum : " << current_sum << endl;
		}
		return;
	}

	// choose
	x[idx] = 1;
	binary(x, a, idx + 1, n, current_sum + a[idx], target);

	// unchoose แล้วไปทางไม่เลือก
	x[idx] = 0;
	binary(x, a, idx + 1, n, current_sum, target);
}


int main(){
	int n = 4 ;
	int a[] = {0,25,10,9,2} ;
	int x[5] ;
	int sumk = 12 ;
	binary(x,a,1,n,0,sumk) ;
	return 0 ;

}
