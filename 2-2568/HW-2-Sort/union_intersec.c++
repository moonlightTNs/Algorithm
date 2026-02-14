#include<iostream>
using namespace std;

int main(){

    int a[] = {6,8,7,4,1} ; 
    int b[] = {3,2,7,1,2} ;
    
    int n = sizeof(a) / sizeof(a[0]) ;
    
    int Arr[1000] = {0} ; 
    int union_map[1000] = {0} ;
    int inter_map[1000] = {0} ;

    int sizeu = 0 ;          
    int u[1000] = {0}; 
    
    for(int i = 0 ; i<n ; i++){
        Arr[a[i]]++ ;
        if(union_map[a[i]] < 1){
            union_map[a[i]]++ ; 
            u[sizeu] = a[i] ;
            sizeu++ ;
        }
    }
    
    int sizein = 0 ;
    int inter[1000] = {0};    
    
    for(int i = 0 ; i< n ; i++){
        if(Arr[b[i]] >=1 ){
            inter_map[b[i]]++ ; 
            inter[sizein] = b[i] ; 
            sizein++ ;
        }
        else{
            if(union_map[b[i]] < 1){
                union_map[b[i]]++ ; 
                u[sizeu] = b[i] ;
                sizeu++ ;
            }
        }
    }

    for(int i = 0 ;i < sizeu ; i++ ){
        cout << u[i] << " ";
    }
    cout << endl ;
    for(int i = 0 ;i < sizein ; i++ ){
        cout << inter[i] << " " ;
    }


    return 0 ;
}