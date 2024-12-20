#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int x = 0;
	int Cout = 0;
	int A[1000] = {};
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int v = 0;
		cin >> v;
		A[i] = v;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] + A[j] == x)
			{
				cout << A[i] << " " << A[j] << endl;
				Cout++;
			}
		}
	}

	if (Cout == 0)
	{
		cout << "-1";
	}

	return 0;
}
