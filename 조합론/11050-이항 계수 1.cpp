#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 101

using namespace std;

int binomial_coefficient(int n, int k)
{
	int dp[MAX][MAX];
	int m;
	for (int i = 0; i <= n; i++)
	{
		m = (i < k) ? i : k;

		for (int j = 0; j <= m; j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	return dp[n][k];
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
	int N, K;
	cin >> N >> K;

	cout << binomial_coefficient(N,K) << endl;

	return 0;
}