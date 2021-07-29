#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define endl "\n"
#define MAX 100001
#define MAX_DEPTH 20

using namespace std;

int N, M, K;
int parent[MAX_DEPTH][MAX];
int depth[MAX];
vector<int> graph[MAX];

void DFS(int current,int level)
{
	// 1.depth를 기록
	depth[current] = level;

	// 2. 자식들의 depth를 기록
	int len = graph[current].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[current][i];
		if (depth[next] == 0)
		{
			DFS(next, level + 1);
			parent[0][next] = current;
		}
	}
}

void fillParent(void)
{
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			parent[i][j] = parent[i-1][parent[i - 1][j]]; // Vertex(정점) j의 2^i번째 조상(1,2,4,8,16...)
		}
	}
}

int LCS(int a, int b)
{
	// 1. depth[a] >= depth[b] 조건 맞추기 => a의 깊이가 b보다 더 아래이다.
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// 2. 더 깊은 a를 2^k승 상승하여 depth 맞추기(depth 맞추기에 초점)
	for (int i = K-1; i >= 0; i--)
	{
		if ((int)pow(2,i) <= depth[a]-depth[b])
		{
			a = parent[i][a];
		}
	}
	// 3. depth를 맞췄는데 같다면 종료.
	if (a == b) return a;
	// 4. a-b는 같은 depth이므로 2^K승 점프하며 공통부모 바로 아래까지 올리기.
	for (int i = K-1; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
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
	1. X와 Y의 높이가 같다면 높이를 하나씩 올려본다.
	2. X와 Y의 높이가 다르다면 높이를 맞춰준다.
	3. 같아 지는 조상을 찾는다.
	! 점화식 DP !
	parent[K][V] = parent[K-1][parent[K-1][V]] : 정점 V의 2^K번째 조상 정점 번호.
	*/
	init();
	cin >> N;
	for (int i = 1; i <= N; i *= 2)
	{
		K++;
	}
	// 그래프의 정보 N만큼 넣어주기.
	for (int i = 1; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		// 양방향 간선 - Root 명확 / 양방향 - Tree 
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	// 부모(조상)노드, Depth정보 테이블에 채우기-> DFS를 이용 => 단절점에서도 사용.
	DFS(1, 1);
	// 부모 채우기
	fillParent();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCS(a, b) << endl;
	}

	return 0;
}