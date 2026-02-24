#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int BFS(vector<vector<int>> &graph, int startVertex, int destVertex,int V) {

  vector<int> dist(V + 1, -1);
  queue<int> q;

  q.push(startVertex);
  dist[startVertex] = 0;

  while (!q.empty()) {

    int currentVertex = q.front();
    q.pop();

    if (currentVertex == destVertex) {
      return dist[currentVertex];
    }

    for (int i = 0; i < graph[currentVertex].size(); i++) {
      int nextVertex = graph[currentVertex][i];
      if (dist[nextVertex] == -1) {
        q.push(nextVertex);
        dist[nextVertex] = dist[currentVertex] + 1;
      }
    }
  }
  return -1; // path not found
}

int main() {

  int n_vertex;
  if (!(cin >> n_vertex))
    return 0;

  vector<vector<int>> list(101); // 1-based index support up to 100

  // Read n adjacency lists
  for (int i = 0; i < n_vertex; i++) {
    int startVertex;
    cin >> startVertex;

    while (true) {
      int nextVertex;
      cin >> nextVertex;

      if (nextVertex == 0) break;
      list[startVertex].push_back(nextVertex);
    }
  }

  // Read source and destination

  int startVertex, endVertex;
  cin >> startVertex >> endVertex;

  int result = BFS(list, startVertex, endVertex, 100);

  cout << result << "\n";

  return 0;
}