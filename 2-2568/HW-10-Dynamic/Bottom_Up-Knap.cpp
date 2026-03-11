#include <iostream>
using namespace std;

long long K[1001][1001];

long long F(int n, int k, int v[], int w[]) {

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){

            if(i == 0 || j == 0){
                K[i][j] = 0;
            }
            else if(w[i-1] > j){
                K[i][j] = K[i-1][j];
            }
            else{
                K[i][j] = max(K[i-1][j], v[i-1] + K[i-1][j - w[i-1]]);
            }

        }
    }

    return K[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    int v[] = {1,4,5,7};
    int w[] = {1,3,4,5};

    cout << F(n, k, v, w);

    return 0;
}
