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
	// 1. 일반 다익스트라처럼 출발점 비용 0 넣고 시작
	// minHeap을 maxHeap으로 바꾸기 위해 연산자 오버라이딩을 하였음.
	priority_queue< pair<int, int>, vector<pair<int, int>>, compare > pq; // {도착지점, 비용} , 비용이 가장 큰게 top()에 있다.
	pq.push({ start,0 }); // 처음 시작해야하는 시작 지점을 우선순위 큐에 넣어준다.
	dist[start].push(0); // 자기 자신은 0이므로 0을 넣어준다.

	// 2. pq를 비울때까지 다익스트라 진행 (K번째 경로를 확인해야하므로 모두 확인)
	while (!pq.empty())
	{
		pair<int, int> now = pq.top();
		pq.pop();

		for (int i = 0; i < adj[now.first].size(); i++)
		{
			pair<int, int> next = adj[now.first][i];

			// 2-1. 저장된 최단비용이 K개 이하인 경우 PQ에 넣기 -> 넣으면 알아서 정렬
			if (dist[next.first].size() < k)
			{
				dist[next.first].push(now.second + next.second);
				// 일반 다익스트라와 동일하게 최솟값이 경신되었으므로 pq에 넣기
				pq.push({ next.first, now.second + next.second });
			}
			// 2-2. 저장된 비용이 K개이므로, dist MAX 값과 비교해서 작은 값을 dist PQ에 갱신 
			else if (dist[next.first].top() > now.second + next.second)
			{
				dist[next.first].pop();	// 뽑기
				dist[next.first].push(now.second + next.second);
				// 일반 다익스트라와 동일하게 최솟값이 갱신되었으므로 pq에 넣기
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
	1 -> 목적지 : K번째 최단경로를 찾아라. 다익스트라 활용.
	int dist[i] = 출발지에서 i까지 가는 최단거리
	priority_queue<int> dist(K);
	K개 크기의 MaxHeap을 만든다.
	MinHeap(최솟값이 맨 위에), K개 크기의 경우 MaxHeap(K번째 값이 맨 위에)을 만든다.
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