#include<iostream>
using namespace std;

int crossarr(int a[] , int l , int mid , int r,int& Lidx , int& Ridx) {

    int sum = 0  ;
    int Lsum = INT_MIN  ; 

    for(int i=mid ; i>=l ; i--){
        sum = sum + a[i]; 
        if(sum > Lsum){
            Lidx = i ;
            Lsum = sum ; 
        }
    }

    sum = 0  ;
    int Rsum = INT_MIN  ; 

    for(int i=mid+1 ; i<=r ; i++){
        sum = sum + a[i]; 
        if(sum > Rsum){
            Ridx = i ; 
            Rsum = sum ; 
        }
    }

    return Lsum + Rsum ; 
}


int maxsubarr(int a[] , int l , int r,int& Lmaxidx ,int& Rmaxidx ){

    if(l==r){
        Lmaxidx = l ;
        Rmaxidx = r ;
        return a[l] ;
    }

    int mid = l + (r-l) /2 ;

    int LStartIdx , LEndIdx , RStartIdx ,REndIdx , CrossStratIdx , CroosEndIdx ; 

    int maxLsum = maxsubarr(a,l,mid,LStartIdx,LEndIdx) ;
    int maxRsum = maxsubarr(a,mid+1,r,RStartIdx,REndIdx) ;
    int maxCsum = crossarr(a,l,mid,r,CrossStratIdx,CroosEndIdx) ; 

    if(maxLsum >= maxRsum && maxLsum  >= maxCsum ){
        Lmaxidx = LStartIdx ;
        Rmaxidx = LEndIdx ;
        return maxLsum ;
    }
    else if(maxRsum >= maxLsum && maxRsum >= maxCsum){
        Lmaxidx = RStartIdx ;
        Rmaxidx = REndIdx ;
        return maxRsum ;
    }
    else {
        Lmaxidx = CrossStratIdx ;
        Rmaxidx = CroosEndIdx ; 
        return maxCsum ; 
    }

}


int main(){
    int a[] = {16, -25, 2, -54, 36, 9, -12, 66};
    int n = sizeof(a) / sizeof(a[0]);

    int LMaxIndex , RMaxIndex ;
    int ans = maxsubarr(a,0,n-1,LMaxIndex,RMaxIndex) ; 

    cout << "Ans :" << ans << endl;
    cout << "Left Index :" << LMaxIndex << endl ;
    cout << "Right Index :" << RMaxIndex ;

    return 0 ; 

}