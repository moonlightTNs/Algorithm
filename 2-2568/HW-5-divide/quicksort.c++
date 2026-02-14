#include<iostream>
using namespace std;

int patition(int a[] , int l , int r){
    int pivot = a[r] ; 
    int i = l ; 
    for(int j =l ; j<r ; j++){
        if(a[j] < pivot){
        swap(a[i],a[j]) ; 
        i++ ;
        }
    }
    swap(a[i] , a[r]) ; 
    return i ; 
}


void quicksort(int a[] , int l ,int r){
int p ; 
if(l<r){
    
    p = patition(a,l,r) ; 
    quicksort(a,l,p-1) ; 
    quicksort(a,p+1,r) ; 
    }
}

int main(){
    
    int n ; 
    cin >> n ;
    int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(a, 0, n - 1); 

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }


    return 0 ; 
}