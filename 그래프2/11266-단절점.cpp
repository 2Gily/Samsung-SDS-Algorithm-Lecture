#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 10001
using namespace std;

int V, E, order,answer;
vector<int> vertex[MAX]; // �׷���(Ʈ��)�� ���� ������ ������ �ִ� ����
int visited[MAX];
bool isCut[MAX]; // ������ bool������ ����(���)�� ǥ��

int dfs(int now, bool isRoot)
{
	visited[now] = ++order; // DFS Ž�� ���� ����(order �湮����)
	int result = visited[now];

	int child = 0; // �ڽ� �� ī��Ʈ

	for (int i = 0; i < vertex[now].size(); i++)
	{
		int next = vertex[now][i];

		if (visited[next] != 0)
		{
			result = min(result, visited[next]);
			continue;
		}

		child++;
		int prev = dfs(next, false);
		
		if (!isRoot && prev >= visited[now])
		{
			isCut[now] = true;
		}

		result = min(result, prev);
	}
	// ��Ʈ����� ��� �ڽ� ��尡 2�� �̻��̸� �������� �ƴϴ�.
	if (isRoot)
	{
		isCut[now] = (child >= 2);
	}
	return result;
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
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int from, to;
		cin >> from >> to;

		vertex[from].push_back(to);
		vertex[to].push_back(from);
	}
	// ��ü ��� DFS�� ���� Ž��
	for (int i = 1; i <= V; i++)
	{
		if (!visited[i]) dfs(i, true);
	}
	// ������ ���� ���
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i]) answer++;
		if (i == V) cout << answer << endl;
	}
	// ������ ����ȣ ���
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i]) cout << i << " ";
	}

	return 0;
}