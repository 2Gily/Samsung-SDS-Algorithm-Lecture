#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 501
#define INF 1e9
using namespace std;

int N, M; // N : 학생의 수, M : 연산의 수
vector<vector<int>> dist;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> M;
	dist.resize(N + 1, vector<int>(N + 1));

	// 1. 2차원 배열에 INF (최댓값)으로 초기화
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = INF;
		}
	}
	// 2. 입력 : a - b 학생의 키 순서를 아는 경우 1로 거리 배열 입력
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
	}
	// 3. 특정 학생이 모든 학생과의 거리를 체크해야하므로 플로이드 워셜 수행
	// 플로이드-워셜 : 경유지 - 출발지 - 도착지 3중 for문
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
	// 4. 모든 학생과의 비교가 가능한 경우
	//    → 거리가 INF 가 아닌 학생의 수가 N-1인 경우 : 키가 몇번째인지 알 수 있으므로 ans++ 
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] != INF || dist[j][i] != INF) cnt++;

		}
		if (cnt == N - 1) answer++;
	}

	cout << answer << endl;

	return 0;
}