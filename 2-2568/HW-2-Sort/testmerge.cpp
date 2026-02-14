#include<iostream>

using namespace std; 

const int maxn = 2000005 ;
long long L[maxn] ;  // ย้ายมา global
long long R[maxn] ;  // ย้ายมา global


void merge(long long a[], int l , int mid ,int r){

    int n1 = mid-l + 1; 
    int n2 = r-mid ; 

    for(int i =0 ; i<n1 ; i++){
        L[i] = a[l+i] ; 
    }
    for(int i =0 ; i<n2 ; i++){
        R[i] = a[mid+1+i] ; 
    }
    //-------------------

    int i = 0 ;
    int j = 0 ; 
    int k =  l ;


    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i] ; 
            i++ ;
        }
        else{
            a[k] = R[j] ;
            j++ ; 
        }
        k++ ; 
    }

    //--------------------------

    while(i < n1){
        a[k] = L[i] ;
        i++ ;
        k++ ; 
    }

    while(j < n2){
        a[k] = R[j] ;
        j++ ;
        k++ ; 
    }
}


void mergesort(long long a[] , int l ,int r ){

    if(l<r){
        int mid = l + (r-l)/2 ;

        mergesort(a,l,mid) ;
        mergesort(a,mid+1,r) ;
        merge(a,l,mid,r) ; 
    }

}






int main(){
    long long a[] = {5,4,3,2,1} ;
    int n = sizeof(a) / sizeof(a[0]) ;
    mergesort(a,0,n-1) ;

    for(int i = 0 ; i<n ; i++){
        cout << a[i] << " " ;
    }


    return 0  ;
}