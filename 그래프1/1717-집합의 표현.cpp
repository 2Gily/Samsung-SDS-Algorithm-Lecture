#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M;
int parent[1000001];

void Init(void)
{
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
}

// Find
int Find(int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}

// Union
void Union(int x, int y) 
{
	x = Find(x);
	y = Find(y);

	parent[y] = x;
}

void sync()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	sync();
	cin >> N >> M;

	Init();
	for (int i = 0; i < M; i++)
	{
		int op, x, y;
		cin >> op >> x >> y;

		if (op == 0)
		{
			Union(x, y);
		}
		else if (op == 1)
		{
			int px = Find(x);
			int py = Find(y);

			if (px == py) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;
}