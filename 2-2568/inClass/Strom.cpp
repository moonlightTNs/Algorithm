#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> G, int StartV, int N)
{

    queue<int> q;
    vector<bool> visited(N, false);

    q.push(StartV);
    visited[StartV] = true; 


    while(!q.empty()){

        int FrontV = q.front() ;
        
        if( == 1){

        }

    }


}

int main()
{

    int R, C;

    cin >> R >> C;

    vector<vector<int>> S(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char Cha;
            cin >> Cha;
            if (Cha == '.')
            {
                S[i][j] = 0;
            }
            if (Cha == '#')
            {
                S[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << S[i][j];
        }
        cout << endl;
    }

    

    return 0;
}