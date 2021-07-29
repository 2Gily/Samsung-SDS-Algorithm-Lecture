#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 100002
using namespace std;

int V, E, order;
vector<int> vertex[MAX];
int visited[MAX];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> answer;

int dfs(int now, int parent)
{
	// 1. �湮���� ��� �� �ڽ�(child)�� �� �غ�	
	visited[now] = ++order;
	int result = visited[now];
	// 2. �ڽ� DFS 
	for (int i = 0; i < vertex[now].size(); i++)
	{
		int next = vertex[now][i];

		// �Դ� �� �����ϱ� ���� ����
		if (next == parent) continue;
		// 2-1. �ڽ��� �̹� �湮�� ���	
		if (visited[next])
		{
			result = min(result, visited[next]);
			continue;
		}
		// 2-2. �ڽ� ���� �湮���� ���
		// �ڽ� ���� �� �湮������ ���� �� 
		int low = dfs(next, now);
		// �ڡڡڡڡ� ������ �Ұ����� ��� ������.
		if (low > visited[now])
		{
			// edge ������� �� ���� ���� �ٲ㼭 ����迭�� �߰� (���� ��� �䱸����) 
			answer.push({ min(now, next), max(now, next) });
		}

		result = min(result, low);
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
		int A, B;
		cin >> A >> B;

		vertex[A].push_back(B);
		vertex[B].push_back(A);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!visited[i]) dfs(i, 0);
	}

	cout << answer.size() << endl;

	int len = answer.size();
	for (int i = 0; i < len; i++)
	{
		cout << answer.top().first << " " << answer.top().second << endl;
		answer.pop();
	}

	return 0;
}