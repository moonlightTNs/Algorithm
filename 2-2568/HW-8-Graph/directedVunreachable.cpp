#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>> &graph, int current,
         vector<bool> &visited)
{
    visited[current] = true;

    for (int i = 0; i < graph[current].size(); i++)
    {
        int neighbor = graph[current][i];
        if (!visited[neighbor])
        {
            DFS(graph, neighbor, visited);
        }
    }
}

int main()
{

    int numVertices;
    cin >> numVertices;

    vector<vector<int>> adjacencyList(numVertices + 1);
    // อ่านข้อมูลกราฟ
    for (int i = 0; i < numVertices; i++)
    {
        int fromVertex;
        cin >> fromVertex;
        while (true)
        {
            int toVertex;
            cin >> toVertex;
            if (toVertex == 0)
                break;
            adjacencyList[fromVertex].push_back(toVertex);
        }
    }

    int numStartNodes;
    cin >> numStartNodes;
    vector<int> startNodes(numStartNodes);
    for (int i = 0; i < numStartNodes; i++)
    {
        cin >> startNodes[i];
    }

    // สำหรับแต่ละ node เริ่มต้น
    for (int i = 0; i < startNodes.size(); i++)
    {
        int start = startNodes[i];
        vector<bool> reachable(numVertices + 1, false);
        DFS(adjacencyList, start, reachable);

        bool foundUnreachable = false;

        for (int v = 1; v <= numVertices; v++)
        {
            if (!reachable[v])
            {
                cout << v << " ";
                foundUnreachable = true;
            }
        }

        if (!foundUnreachable)
            cout << 0;

        cout << endl;
    }

    return 0;
}