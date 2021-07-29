#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <climits>
#define INF INT_MAX
#define V_MAX 20001
#define E_MAX 300001

using namespace std;

int v, e, start; // v : 정점의 개수, e : 간선의 개수, start : 시작 정점의 번호

vector<pair<int, int> > graph[V_MAX]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[E_MAX]; // 최단 거리 테이블 만들기

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq; // 거리, 노드 인덱스

	pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first; //현재 노드까지의 비용
		int now = pq.top().second; // 현재 노드
		pq.pop();

		if (d[now] < dist) // 이미 최단경로를 체크한 노드인 경우 패스
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
												  // 현재노드까지 비용 + 다음 노드 비용
			if (cost < d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

void init(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(void)
{
    init();
	cin >> v >> e;
	cin >> start;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b, c });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + E_MAX, INF);

	// 다익스트라 알고리즘을 수행
	dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= v; i++)
	{
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (d[i] == INF) 
        {
			cout << "INF" << '\n';
		}
		// 도달할 수 있는 경우 거리를 출력
		else 
        {
			cout << d[i] << '\n';
		}
	}

	return 0;
}