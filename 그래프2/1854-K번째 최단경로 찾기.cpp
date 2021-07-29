#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define endl "\n"
#define MAX 1001
#define INF 1e9
using namespace std;

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int n, m, k;
vector<pair<int, int>> adj[MAX];
priority_queue<int> dist[MAX];

void kthDijkstra(int start)
{
	// 1. �Ϲ� ���ͽ�Ʈ��ó�� ����� ��� 0 �ְ� ����
	// minHeap�� maxHeap���� �ٲٱ� ���� ������ �������̵��� �Ͽ���.
	priority_queue< pair<int, int>, vector<pair<int, int>>, compare > pq; // {��������, ���} , ����� ���� ū�� top()�� �ִ�.
	pq.push({ start,0 }); // ó�� �����ؾ��ϴ� ���� ������ �켱���� ť�� �־��ش�.
	dist[start].push(0); // �ڱ� �ڽ��� 0�̹Ƿ� 0�� �־��ش�.

	// 2. pq�� ��ﶧ���� ���ͽ�Ʈ�� ���� (K��° ��θ� Ȯ���ؾ��ϹǷ� ��� Ȯ��)
	while (!pq.empty())
	{
		pair<int, int> now = pq.top();
		pq.pop();

		for (int i = 0; i < adj[now.first].size(); i++)
		{
			pair<int, int> next = adj[now.first][i];

			// 2-1. ����� �ִܺ���� K�� ������ ��� PQ�� �ֱ� -> ������ �˾Ƽ� ����
			if (dist[next.first].size() < k)
			{
				dist[next.first].push(now.second + next.second);
				// �Ϲ� ���ͽ�Ʈ��� �����ϰ� �ּڰ��� ��ŵǾ����Ƿ� pq�� �ֱ�
				pq.push({ next.first, now.second + next.second });
			}
			// 2-2. ����� ����� K���̹Ƿ�, dist MAX ���� ���ؼ� ���� ���� dist PQ�� ���� 
			else if (dist[next.first].top() > now.second + next.second)
			{
				dist[next.first].pop();	// �̱�
				dist[next.first].push(now.second + next.second);
				// �Ϲ� ���ͽ�Ʈ��� �����ϰ� �ּڰ��� ���ŵǾ����Ƿ� pq�� �ֱ�
				pq.push({ next.first, now.second + next.second });
			}
		}
	}
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
	/*
	1 -> ������ : K��° �ִܰ�θ� ã�ƶ�. ���ͽ�Ʈ�� Ȱ��.
	int dist[i] = ��������� i���� ���� �ִܰŸ�
	priority_queue<int> dist(K);
	K�� ũ���� MaxHeap�� �����.
	MinHeap(�ּڰ��� �� ����), K�� ũ���� ��� MaxHeap(K��° ���� �� ����)�� �����.
	*/
	init();
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;

		adj[from].push_back({ to,time });
	}

	kthDijkstra(1);

	for (int i = 1; i <= n; i++)
	{
		if (dist[i].size() == k)
		{
			cout << dist[i].top() << endl;
		}
		else cout << -1 << endl;
	}

	return 0;
}