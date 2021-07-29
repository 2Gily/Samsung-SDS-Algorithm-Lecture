#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 100005
using namespace std;

int N, M;
int parent[MAX];
long long dist[MAX];

int Find(int idx)
{
	// 1.root인 경우 기준 union-find와 동일
	if (parent[idx] == idx)
	{
		return idx;
	}
	// 2.root가 아닌 경우 root와 거리를 구해서 갱신
	int parent_idx = Find(parent[idx]);
	dist[idx] += dist[parent[idx]];
	return parent[idx] = parent_idx;
}

void Union(int a, int b, int diff)
{
	int pa = Find(a);
	int pb = Find(b);

	// 이미 같은 그룹이면 거리 계산이 되어있으므로 종료
	if (pa == pb) return;

	// parent를 변경하고, 무게 차이를 계산함.
	dist[pb] = dist[a] - dist[b] + diff;
	parent[pb] = pa;

	return;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
			dist[i] = 0;
		}
		
		char op;
		int a, b, w;

		for (int i = 0; i < M; i++)
		{
			cin >> op;

			if (op == '!')
			{
				cin >> a >> b >> w;
				Union(a, b, w);
			}
			else if (op == '?')
			{
				cin >> a >> b;
				if (Find(a) != Find(b))
				{
					cout << "UNKNOWN" << endl;
				}
				else
				{
					cout << dist[b] - dist[a] << endl;
				}
			}
		}
	}

	return 0;
}