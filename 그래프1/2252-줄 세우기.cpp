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
	비교를 하는데 cost가 얼마인지 모른다?
	"상대적인 키 차이" = "위상"만 아는 상황

	1~N 학생 32,000명 2명씩 비교한 키만 가지고 전체를 비교하는 문제
	정답이 여러개(순서가 여러개)인 경우 아무거나 출력한다.
	*/
	init();
	cin >> N >> M;

	// 진입차수(inDegree)를 input 받는다.
	student.resize(N + 1);
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int to, from;
		cin >> to >> from;

		adj[from].push_back(to);
		student[to]++;
	}
	// 진입차수 0인 애들 초기 Queue에 적재.
	for (int i = 1; i <= N; i++)
	{
		if (student[i] == 0) q.push(i);
	}
	// Queue에서 1개씩 뽑으면서 연결된 간선 끊어주기
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