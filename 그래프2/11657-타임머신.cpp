#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 502
#define INF 1e9
using namespace std;

typedef struct INFO {
	int start;
	int end;
	int cost;
}INFO;

int N, M;
long long dist[MAX];
vector<INFO> graph; // ������� start, end, cost

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;
		graph.push_back({ start, end, cost });
	}

	// 1.�ʱ�ȭ -> ��� ������ ���� ��� INF ����, ���� ���� ��� 0���� ����.
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[1] = 0;

	// 2. ���� E�� ���� M, M-1��ŭ ����, ������ 
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < graph.size(); i++)
		{
			int start = graph[j].start;
			int end = graph[j].end;
			int cost = graph[j].cost;

			// 2-1. �����ϴ� ������ ����� ���� INF��� Pass
			if (dist[end] == INF) continue;
			// 2-2. �����ϴ� ������ ��뺸�� ���� ��� ���� + �ش� ������ ����� �� �۴ٸ� ����
			if (dist[end] > dist[start] + cost) dist[end] = dist[start] + cost;
		}
	}

	// 3. ���� ����Ŭ üũ N-1�������� �Ÿ� ���, N���� ���� ����Ŭ üũ
	for (int j = 0; j < graph.size(); j++)
	{
		int start = graph[j].start;
		int end = graph[j].end;
		int cost = graph[j].cost;

		// 3-1. �����ϴ� ������ ����� ���� INF��� Pass
		if (dist[end] == INF) continue;
		// 3-2. �����ϴ� ������ ��뺸�� ���� ��� ���� + �ش� ������ ����� �� �۴ٸ� ���� ����Ŭ�� ����(���� ���� ����Ŭ�� ���� ��� �۾���)
		if (dist[end] > dist[start] + cost)
		{
			cout << -1 << endl;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}

	return 0;
}