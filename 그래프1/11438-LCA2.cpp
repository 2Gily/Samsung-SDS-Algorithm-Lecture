#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define endl "\n"
#define MAX 100001
#define MAX_DEPTH 20

using namespace std;

int N, M, K;
int parent[MAX_DEPTH][MAX];
int depth[MAX];
vector<int> graph[MAX];

void DFS(int current,int level)
{
	// 1.depth�� ���
	depth[current] = level;

	// 2. �ڽĵ��� depth�� ���
	int len = graph[current].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[current][i];
		if (depth[next] == 0)
		{
			DFS(next, level + 1);
			parent[0][next] = current;
		}
	}
}

void fillParent(void)
{
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			parent[i][j] = parent[i-1][parent[i - 1][j]]; // Vertex(����) j�� 2^i��° ����(1,2,4,8,16...)
		}
	}
}

int LCS(int a, int b)
{
	// 1. depth[a] >= depth[b] ���� ���߱� => a�� ���̰� b���� �� �Ʒ��̴�.
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// 2. �� ���� a�� 2^k�� ����Ͽ� depth ���߱�(depth ���߱⿡ ����)
	for (int i = K-1; i >= 0; i--)
	{
		if ((int)pow(2,i) <= depth[a]-depth[b])
		{
			a = parent[i][a];
		}
	}
	// 3. depth�� ����µ� ���ٸ� ����.
	if (a == b) return a;
	// 4. a-b�� ���� depth�̹Ƿ� 2^K�� �����ϸ� ����θ� �ٷ� �Ʒ����� �ø���.
	for (int i = K-1; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	1. X�� Y�� ���̰� ���ٸ� ���̸� �ϳ��� �÷�����.
	2. X�� Y�� ���̰� �ٸ��ٸ� ���̸� �����ش�.
	3. ���� ���� ������ ã�´�.
	! ��ȭ�� DP !
	parent[K][V] = parent[K-1][parent[K-1][V]] : ���� V�� 2^K��° ���� ���� ��ȣ.
	*/
	init();
	cin >> N;
	for (int i = 1; i <= N; i *= 2)
	{
		K++;
	}
	// �׷����� ���� N��ŭ �־��ֱ�.
	for (int i = 1; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		// ����� ���� - Root ��Ȯ / ����� - Tree 
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	// �θ�(����)���, Depth���� ���̺� ä���-> DFS�� �̿� => ������������ ���.
	DFS(1, 1);
	// �θ� ä���
	fillParent();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCS(a, b) << endl;
	}

	return 0;
}