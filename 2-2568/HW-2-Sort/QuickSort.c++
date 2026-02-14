#include<iostream>
using namespace std;


int pati(int a[] , int l , int r){
    int mid = (l+r) /2 ; 
    if(a[l] > a[mid]) swap(a[l],a[mid]) ; 
    if(a[l] > a[r]) swap(a[l],a[r]) ;
    if(a[mid] > a[r]) swap(a[mid],a[r]) ;

    swap(a[mid] ,a[r]) ; 

    int pivot = a[r] ;

    int i = l ; 
    for(int j=l ; j<r ; j++){
        if(a[j]<pivot){
            swap(a[i],a[j]) ; 
            i++ ;
        }
    }
    swap(a[i],a[r]) ;
    return i ; 
}

void quicksort(int a[] , int l, int r, int &count){
    if(l < r){
        count++ ;
        int p = pati(a,l,r) ; 
        quicksort(a,l,p-1,count) ; 
        quicksort(a,p+1,r,count) ;
    }
}


int main(){
    
    int a[100]={32,100,24,999,66,33,10,20} ; 
    int n = 8 ;
    int count = 0;
    quicksort(a,0,n-1,count) ;
    
    for(int i=0 ; i<n ; i++){
        cout << a[i] << " "  ;
    }
    cout << endl ;
    cout << "Recursive count: " << count ;
    return 0 ; 
}













