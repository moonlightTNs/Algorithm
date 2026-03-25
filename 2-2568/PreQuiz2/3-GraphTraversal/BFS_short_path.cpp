#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(vector<vector<int>>& graph, int startVertex, vector<int>& parent)
{ vector<bool> visited(graph.size(), false);
  queue<int> queue;
  queue.push(startVertex);
  visited[startVertex] = true;

  while (!queue.empty()) {
    int currentVertex = queue.front();
        queue.pop();
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[currentVertex][i] && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                parent[i] = currentVertex;
            }
        }
    }
}

int main() {
     int n;
     cin>>n;
     vector<vector<int>> graph(n, vector<int>(n, 0));
     int i, j, u, v, x, y;
     for(i=0; i < n; i++)
     { cin >> u;
       cin >> v;
        while(v != 0)
         {  graph[u-1][v-1] = 1;
            cin>>v;
         }
     }
    cin >> x >> y;

    vector<int> parent(graph.size(), -1);

    BFS(graph, x-1, parent);

    int cnt = 0;
    y = parent[y-1];
    while(y != -1)
      {  y = parent[y];
         cnt++;
      }
     cout<< cnt;


    return 0;
}
