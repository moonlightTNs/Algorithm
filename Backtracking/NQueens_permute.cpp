#include <bits/stdc++.h>
//N queens
using namespace std ; 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool safe(int X[] , int start){
	for(int i =1 ; i <start; i++){
		if(abs(X[i] - X[start]) == abs(i - start) || X[i] == X[start]){
			return false;
		}
	}
	return true ;
}

void permute(int X[], int start, int end) {
    if (start == end+1) {

        for (int i = 1; i <= end; i++) {
            cout << X[i] << " "   ;
        }
        cout << endl ; 
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&X[start], &X[i]);
        if(safe(X,start)){
        	permute(X, start + 1, end);	
		}  
        swap(&X[start], &X[i]);
    }
}

int main() {
    int n = 4;
    int X[] = {-1, 1, 2, 3, 4};

    permute(X, 1, n);

    return 0;
}
