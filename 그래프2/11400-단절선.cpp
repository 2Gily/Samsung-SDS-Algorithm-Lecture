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
	// 1. 방문순서 기록 후 자식(child)과 비교 준비	
	visited[now] = ++order;
	int result = visited[now];
	// 2. 자식 DFS 
	for (int i = 0; i < vertex[now].size(); i++)
	{
		int next = vertex[now][i];

		// 왔던 길 제외하기 위한 로직
		if (next == parent) continue;
		// 2-1. 자식을 이미 방문한 경우	
		if (visited[next])
		{
			result = min(result, visited[next]);
			continue;
		}
		// 2-2. 자식 최초 방문했을 경우
		// 자식 정점 중 방문순서가 빠른 값 
		int low = dfs(next, now);
		// ★★★★★ 역전이 불가능한 경우 단절선.
		if (low > visited[now])
		{
			// edge 출발점이 더 작은 수로 바꿔서 정답배열에 추가 (문제 출력 요구사항) 
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