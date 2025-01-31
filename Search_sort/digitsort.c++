#include <bits/stdc++.h>
using namespace std;



int patition(int a[],int l ,int r){

    int pivot = a[r] ; 

    int i = l - 1  ; 

    for(int j = l  ; j <= r ; j++ ){
        if(a[j] < pivot){
            i++ ;  
            swap(a[i],a[j]) ; // i++ ก่อนสลับ 
        }
    }
    swap(a[i+1],a[r]) ; 
    return i+1 ;
}

void quick(int a[], int l , int r){

    if(l<r){
        int p = patition(a,l,r); 
        quick(a,l,p-1) ; 
        quick(a,p+1,r) ; 
    }

}


int main(){

    int n = 936486 ; 

    if( n > 1000000 && n < 1){
        return 1 ; 
    }

    int index = 0 ;

    int a[6] = {} ; 

    for(int i = 5 ; i >=0 ; i--){

    int  X = round(pow(10, i)) ; 

    int temp =  n %  X ;  
    int sad = n - temp  ; 
    int result = sad / X;
    n = temp  ; 
    a[index] = result ; 
    index ++ ; 
    }

    quick(a,0,index-1) ; 

    for(int i=0 ; i< index ;i++){
        cout << a[i] ; 
    }
    return 0 ; 




    

}