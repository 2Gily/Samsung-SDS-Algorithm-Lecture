#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 10001
#define MOD 1'000'000'007
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
using namespace std;

int N;
int height[MAX];
int dp[MAX][MAX / 2 + 2];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	1) 어떻게 풀 것인가?

	문제 조건 몇가지를 정리해봤다.

	① 첫 열과 마지막 열의 높이는 0이다.
	② 인접열의 높이 차이는 1
	→ 각 열의 가능한 높이 <= min(i, (N-1) -i )
	1번째열    : 0
	2번째열    : 0, 1
	3번째열    : 0, 1, 2

	i번째열    : 0, 1, .... min(i, (N-1) -i )

	N-2번째열 : 0, 1, 2
	N-1번째열 : 0, 1
	N번째열    : 0

	dp[i][j] = i번째 열의 높이가 j일때 i번째 열까지의 가능한 제단 경우의 수
	dp[N][K] = dp[N-1][K-1] + dp[N-1][K] + dp[N-1][K+1]
	*/
	init();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> height[i];
		if (height[i] > MIN(i, (N - 1) - i))
		{
			cout << 0 << endl;
			return 0;
		}
	}
	// 2. dp 실행
	dp[0][0] = 1;
	int len;

	for (int i = 1; i < N; i++)
	{
		// dp배열 초기화 후 실행
		len = MIN(i, (N - 1) - i);
		for (int j = 0; j <= len; j++)
		{
			dp[i][j] = 0;
		}

		// 2-1. 높이를 모르는 상태 - 0 ~ min(i, (N-1)-i) 가능
		if (height[i] == -1)
		{
			len = MIN(i, (N - 1) - i);
			for (int j = 0; j <= len; j++)
			{

				// 인접 열 높이 대비 +/- 1 높이만 가능
				for (int k = -1; k <= 1; k++)
				{
					int adjHeight = j + k;
					if (adjHeight < 0) continue;

					dp[i][j] += dp[i - 1][adjHeight];
					dp[i][j] %= MOD;
				}
			}
		}
		// 2-2. 높이를 아는 상태
		else {
			for (int k = -1; k <= 1; k++)
			{
				int adjHeight = height[i] + k;
				if (adjHeight < 0) continue;

				dp[i][height[i]] += dp[i - 1][adjHeight];
				dp[i][height[i]] %= MOD;
			}
		}
	}

	cout << dp[N - 1][0] % MOD << endl;

	return 0;
}