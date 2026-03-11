#include <iostream>
using namespace std;

long long K[1001][1001];

long long M(int i, int j, int v[], int w[]) {

    if (i == 0 || j == 0){
    	return 0;
	}

    if (K[i][j] != -1){
    	return K[i][j];
	}
        
    if (w[i-1] > j){
    	return K[i][j] = M(i-1, j, v, w);
	}
        

    return K[i][j] = max(M(i-1, j, v, w),v[i-1] + M(i-1, j - w[i-1], v, w)
    );
}

int main() {
    int n, k;
    cin >> n >> k;

    int v[] = {1,4,5,7};
    int w[] = {1,3,4,5};

    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            K[i][j] = -1;

    cout << M(n, k, v, w);

    return 0;
}
