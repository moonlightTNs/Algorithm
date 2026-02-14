#include <iostream>
using namespace std;


int patition(int a[] , int l , int r){
    int pivot  = a[r] ; 
    int i = l ; 
    
    for(int j=i ; j<r ; j++ ){
        if(a[j] < pivot){
            swap(a[i],a[j]) ;
            i++ ; 
        }
    }
    swap(a[i],a[r]) ;
    return i ; 
}



void quick(int a[],int l ,int r){

    if(l<r){
        int pivot  = patition(a,l,r) ; 
        quick(a,l,pivot-1) ; 
        quick(a,pivot+1,r) ; 
    }
}



int main(){

    int a[] = {30,40,1,5,10,20} ; 
    int n = sizeof(a) / sizeof(a[0]) ; 

    quick(a,0,n-1) ; 
    cout << n << endl ;
    for(int i =0 ; i<n ; i++){
        cout << a[i] << " " ;
    }

    return 0 ;
}