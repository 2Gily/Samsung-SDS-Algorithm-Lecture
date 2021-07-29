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
	1) ��� Ǯ ���ΰ�?

	���� ���� ����� �����غô�.

	�� ù ���� ������ ���� ���̴� 0�̴�.
	�� �������� ���� ���̴� 1
	�� �� ���� ������ ���� <= min(i, (N-1) -i )
	1��°��    : 0
	2��°��    : 0, 1
	3��°��    : 0, 1, 2

	i��°��    : 0, 1, .... min(i, (N-1) -i )

	N-2��°�� : 0, 1, 2
	N-1��°�� : 0, 1
	N��°��    : 0

	dp[i][j] = i��° ���� ���̰� j�϶� i��° �������� ������ ���� ����� ��
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
	// 2. dp ����
	dp[0][0] = 1;
	int len;

	for (int i = 1; i < N; i++)
	{
		// dp�迭 �ʱ�ȭ �� ����
		len = MIN(i, (N - 1) - i);
		for (int j = 0; j <= len; j++)
		{
			dp[i][j] = 0;
		}

		// 2-1. ���̸� �𸣴� ���� - 0 ~ min(i, (N-1)-i) ����
		if (height[i] == -1)
		{
			len = MIN(i, (N - 1) - i);
			for (int j = 0; j <= len; j++)
			{

				// ���� �� ���� ��� +/- 1 ���̸� ����
				for (int k = -1; k <= 1; k++)
				{
					int adjHeight = j + k;
					if (adjHeight < 0) continue;

					dp[i][j] += dp[i - 1][adjHeight];
					dp[i][j] %= MOD;
				}
			}
		}
		// 2-2. ���̸� �ƴ� ����
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