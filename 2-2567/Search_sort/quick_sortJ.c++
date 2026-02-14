#include <bits/stdc++.h>
using namespace std;


int patition(int a[] , int l , int r  ){
   
   int mid = (l + r) / 2;
    if (a[l] > a[mid]) swap(a[l], a[mid]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[mid] > a[r]) swap(a[mid], a[r]);
    swap(a[r], a[mid]); 
    int pivot = a[r] ;

    int i = l - 1 ; 

    for(int j = l ; j<=r ; j++){

        if(a[j] < pivot){ 
            i++ ; 
            swap(a[i] , a[j]) ;
        }
    }
    swap(a[i+1] , a[r]) ;

return i+1 ; 

}

void quick(int a[],int l, int r ){

    if(l<r){
        int p = patition(a,l,r) ;
        quick(a,l,p-1);
        quick(a,p+1,r);
    }


}



int main()
{

    int n = 10;
    int a[n] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};

   
    quick(a,0,n-1) ; 
     for(int i =0 ;i<n ; i++){
        cout << a[i] << " " ; 
     }

    return 0;
}