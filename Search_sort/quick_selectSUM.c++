#include<bits/stdc++.h>

using namespace std ;

int patition(int a[] , int l , int r){

    int pivot = a[r] ;

    int i = l-1 ; 
    for(int j =l ; j<=r ; j++){
        if(a[j] < pivot){
            i++  ; 
            swap(a[i] , a[j]); 
        }
    }
    swap(a[i+1],a[r]) ; 

return i+1 ;

}



int QS(int a[] , int l ,int r, int k ){

    if(l == r){// base case 
        return a[l] ;
    }
    int p = patition(a,l,r) ; 
    if(k == p){ // base case 
        return a[p] ; 
    }
    
    if(k < p){
        return QS(a,l,p-1,k) ; 
    }
    else{
        return QS(a,p+1,r,k)  ; 
    }


}


int main()
{
    int  n ,m ; 
     // int a[n] = {1, 5 ,10, 4, 8, 2, 6}; // 1 + 6 + 4
     cin >> n ;
    int a[n] = {};
    for(int i = 0 ; i<n ; i++){
        cin >> a[i] ;
    }
    
    cin >> m ;
    int k[m] = {} ; 
    for(int j = 0 ; j< m ; j++){
        int t;
        cin >> t;
        k[j] = t-1; 
    }


    int count = 0 ;
    for(int i = 0 ; i < m ; i++){
        count += QS(a,0,n-1,k[i]);
    }

    cout << count ;

    return 0;
}