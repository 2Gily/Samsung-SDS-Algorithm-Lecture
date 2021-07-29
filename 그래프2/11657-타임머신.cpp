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
vector<INFO> graph; // 순서대로 start, end, cost

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;
		graph.push_back({ start, end, cost });
	}

	// 1.초기화 -> 모든 정점에 대한 비용 INF 설정, 시작 정점 비용 0으로 설정.
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[1] = 0;

	// 2. 간선 E의 개수 M, M-1만큼 갱신, 마지막 
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < graph.size(); i++)
		{
			int start = graph[j].start;
			int end = graph[j].end;
			int cost = graph[j].cost;

			// 2-1. 도착하는 정점의 비용이 아직 INF라면 Pass
			if (dist[end] == INF) continue;
			// 2-2. 도착하는 정점의 비용보다 현재 출발 정점 + 해당 정점의 비용이 더 작다면 갱신
			if (dist[end] > dist[start] + cost) dist[end] = dist[start] + cost;
		}
	}

	// 3. 음수 사이클 체크 N-1번까지는 거리 기록, N번은 음수 사이클 체크
	for (int j = 0; j < graph.size(); j++)
	{
		int start = graph[j].start;
		int end = graph[j].end;
		int cost = graph[j].cost;

		// 3-1. 도착하는 정점의 비용이 아직 INF라면 Pass
		if (dist[end] == INF) continue;
		// 3-2. 도착하는 정점의 비용보다 현재 출발 정점 + 해당 정점의 비용이 더 작다면 음수 사이클이 있음(이유 음수 사이클을 돌면 계속 작아짐)
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