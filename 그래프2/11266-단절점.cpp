#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 10001
using namespace std;

int V, E, order,answer;
vector<int> vertex[MAX]; // 그래프(트리)의 연결 정보를 가지고 있는 벡터
int visited[MAX];
bool isCut[MAX]; // 단절점 bool형으로 정점(노드)에 표시

int dfs(int now, bool isRoot)
{
	visited[now] = ++order; // DFS 탐색 순서 지정(order 방문순서)
	int result = visited[now];

	int child = 0; // 자식 수 카운트

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
	// 루트노드인 경우 자식 노드가 2개 이상이면 단절점이 아니다.
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
	// 전체 노드 DFS를 통해 탐색
	for (int i = 1; i <= V; i++)
	{
		if (!visited[i]) dfs(i, true);
	}
	// 단절점 개수 출력
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i]) answer++;
		if (i == V) cout << answer << endl;
	}
	// 단절점 노드번호 출력
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i]) cout << i << " ";
	}

	return 0;
}