#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>> &graph, int start)
{
	vector<bool> visited(graph.size(), false);
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		cout << u << " ";

		for (int i = 0; i < (int)graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int start;
	cin >> start;

	bfs(graph, start);

	cout << endl;
	return 0;
}
