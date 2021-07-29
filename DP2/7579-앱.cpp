#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M; // 활성화된 앱의 수, 메모리 공간
int m[101] = { 0, };
int c[101] = { 0, };
int dp[101][10001] = { 0, };
int result = 1e9;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	<배낭(Knapsack) 유사 문제>

	배낭 문제는 두가지로 분류된다.
	1. 물건을 쪼갤 수 있는 배낭문제(Fraction Knapsack Problem)
	2. 물건을 쪼갤 수 없는 배낭문제(0/1 Knapsack Problem)
	
	1. 물건을 쪼갤 수 있는 배낭문제의 경우는 가치가 큰 물건부터 담고, 남은 무게 만큼 물건을 쪼개는 방식으로 그리디 알고리즘을 사용.
	2. 물건을 쪼갤 수 없는 배낭문제의 경우는 동적계획법을 사용.

	[전제조건]

	n은 물건개수, k는 가져갈 수 있는 무게값
	w[]는 물건에 대한 무게값들
	v[]는 해당 물건에 대한 가치값

	i는 i번째 물건 j는 무게를 나타.
	즉, dp[i][j]는 i번째 물건까지 최대 j무게까지 가능할때 최고의 가치값.

	점화식은
	if(w[i]<=j) 일때는
	dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]
	else
	dp[i][j] = dp[i - 1][j]

	앱 - 보석
	메모리 - 무게
	활성화비용 - 가치
	*/
	init();
	cin >> N >> M;

	for (int i = 1; i <= N; i++) 
	{
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) 
	{
		cin >> c[i];
	}

	// dp[i][j] => i번째까지 앱, 비활성화시 필요한 자원의 양 j의 최대값(100*100)
	for (int i = 1; i <= N; i++) 
	{
		for (int j = 0; j <= 10000; j++) 
		{
			if (c[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= M) result = min(result, j);
		}
	}

	cout << result << endl;


	return 0;
}