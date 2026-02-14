#include<iostream>
using namespace std ;

const int MAXN = 200005 ; 


int FisrtIndex(int a[], int n , int target){
    int l = 0 , r = n-1 ,index = -1 ; 

    while(l<=r){
        int mid = l +(r-l)/2 ;
        if(a[mid] == target){
            index = mid ;
            r = mid - 1 ;
        }

        else if(a[mid] < target ){
            l = mid + 1 ; 
        }
        else{
            r = mid -1 ;
        }
    }
    return index ; 

}
int LastIndex(int a[], int n , int target){
    int l = 0 , r = n-1 ,index = -1 ; 

    while(l<=r){
        int mid = l +(r-l)/2 ;
        if(a[mid] == target){
            index = mid ;
            l = mid + 1 ;
        }

        else if(a[mid] < target ){
            l = mid + 1 ; 
        }
        else{
            r = mid -1 ;
        }
    }
    return index ; 

}

int countdup(int a[] , int n , int target){

    int fisrt = FisrtIndex(a,n,target) ;
    if(fisrt == -1) return 0 ;
    int last = LastIndex(a,n,target) ;

    return last - fisrt + 1 ;
}






int partition(int a[],int l ,int r){

    int pivot = a[r] ;
    int i = l ;

    for(int j = l ; j<r ; j++){
        if(a[j] < pivot){
            swap(a[i],a[j]) ;
            i++ ;
        }
    }
    swap(a[i] , a[r]) ; 
    return i ; 
}

void quicksort(int a[] , int l , int r){

    if(l<r){
        int p = partition(a,l,r) ;
        quicksort(a,l,p-1) ;
        quicksort(a,p+1,r) ; 
    }

}


int main(){

    int a[] = { 2,3,4,3,5,5,2,5,6} ;
    int n = sizeof(a) / sizeof(a[0]) ;

    quicksort(a,0,n-1) ;
    int count = countdup(a,n-1,5) ;
    cout << count ;
    return 0 ;
}