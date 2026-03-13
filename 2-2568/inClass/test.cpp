#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> G, int StartV, int V, int n)
{

    queue<int> q;
    vector<bool> visited(V, false);

    q.push(StartV);
    visited[StartV] = true;

    while (!q.empty())
    {
        int frontV = q.front();
        q.pop();
        cout << frontV << " ";
        for (int i = 0; i < n; i++)
        {
            int nextV = G[frontV][i];
            if (nextV == 1)
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    //<type> name( size , fill )
    vector<vector<int>> Matrix(n, vector<int>(n ,0));

    for (int i = 0; i < k; i++)
    {
        int st, end;
        cin >> st >> end;
        // Matrix[st].push_back(end);
        Matrix[st][end] = 1;
    }

    // for(int i = 0 ; i < Matrix.size() ; i++){
    //     cout << i << ":"  ;
    //     for(int j = 0 ; j < Matrix[i].size(); j++){
    //         cout << Matrix[i][j] << " " ;
    //     }
    //     cout << endl  ;
    // }

    int numV = Matrix.size();

    BFS(Matrix, 2, numV , n);

    return 0;
}
