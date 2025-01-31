#include <iostream>

using namespace std;

int patition(int a[], int l ,int r ){
    int pivot = a[r] ; 

    int i = l-1 ;

    for(int j = l ; j <= r ; j++){
        if(a[j] < pivot){
            i++ ; 
            swap(a[i] , a[j]) ;
        }
    }
    swap(a[i+1],a[r]) ;

return i+1; 

}





int QS(int a[] , int l , int r , int k){

    if(l == r){
        return a[l] ; 
    }

    int p = patition(a,l,r) ;

    if(k==p){
        return a[p] ; 
    }
    if(k > p){
        return QS(a,p+1,r,k) ; 
    }
    else{
        return QS(a,l,p-1,k) ; 
    }

}




int main()
{

    int n, m;
    cin >> n;
    int a[n] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    int k[m] = {};
    for (int i = 0; i < m; i++)
    {
        int t  ;
        cin >> t;
        k[i] = t-1 ;
    }

   int count =  0 ;
    for(int i = 0 ; i< m ; i++){
        count  +=  QS(a,0,n-1,k[i]);
        cout << count << " " ;   
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << k[i] << " ";
    // }

    return 0;
}