#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 3201
using namespace std;

int N, M;
vector<int> student, answer;
vector<vector<int>> adj;
queue<int> q;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	- Memo -
	�񱳸� �ϴµ� cost�� ������ �𸥴�?
	"������� Ű ����" = "����"�� �ƴ� ��Ȳ

	1~N �л� 32,000�� 2�� ���� Ű�� ������ ��ü�� ���ϴ� ����
	������ ������(������ ������)�� ��� �ƹ��ų� ����Ѵ�.
	*/
	init();
	cin >> N >> M;

	// ��������(inDegree)�� input �޴´�.
	student.resize(N + 1);
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int to, from;
		cin >> to >> from;

		adj[from].push_back(to);
		student[to]++;
	}
	// �������� 0�� �ֵ� �ʱ� Queue�� ����.
	for (int i = 1; i <= N; i++)
	{
		if (student[i] == 0) q.push(i);
	}
	// Queue���� 1���� �����鼭 ����� ���� �����ֱ�
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int next : adj[current])
		{
			student[next]--;

			if (student[next] == 0) q.push(next);
		}
		answer.push_back(current);
	}

	reverse(answer.begin(), answer.end());

	for (auto a : answer)
	{
		cout << a << " ";
	}

	return 0;
}