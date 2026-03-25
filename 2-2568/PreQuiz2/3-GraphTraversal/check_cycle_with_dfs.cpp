#include <iostream>
#include <vector>

using namespace std;

bool cycleFound = false;

void DFS(vector<vector<int>>& graph, int u, int V,
         vector<bool>& visited, vector<bool>& recStack)
{
    visited[u] = true;
    recStack[u] = true;

    for (int v = 0; v < V; v++)
    {  if (graph[u][v])
        {
            if (!visited[v])
            {
                DFS(graph, v, V, visited, recStack);
            }
            else if (recStack[v]) // check back edge
            {
                cycleFound = true;
                return;
            }
        }
    }

    recStack[u] = false;
}

bool hasCycle(vector<vector<int>>& graph, int V)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(graph, i, V, visited, recStack);
            if (cycleFound) return true;
        }
    }
    return false;
}

int main()
{
    int V = 4;
    vector<vector<int>> graph = {
        //0 1 2 3
        {0,1,1,0}, // 0 -> 1, 0 -> 2
        {0,0,1,0}, // 1 -> 2
        {1,0,0,1}, // 2 -> 0, 2 -> 3
        {0,0,0,0}  // 3
    };

    if (hasCycle(graph, V))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
