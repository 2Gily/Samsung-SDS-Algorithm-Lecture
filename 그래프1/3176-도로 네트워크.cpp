#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 100001

using namespace std;

typedef pair<int, int> PAIR;

int N, K;
vector<PAIR> city[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
	*/

	init();
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int A, B, C; // A도시, B도시, A-B를 잇는 다리의 길이
		cin >> A >> B >> C;

		city[A].push_back({ B,C });
		city[B].push_back({ A,C });
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int D, E;
		cin >> D >> E;
	}

	return 0;
}