#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 101

using namespace std;

int N, M, K; // a : N��, z : M��, ������ K��° ���ڿ�
int dp[MAX][MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int combination(int n, int r) // �Ľ�Į �ﰢ�� ����� ����, DP�� �̿�
{
	if (n == r || r == 0)
	{
		return 1;
	}
	else if (dp[n][r] != 0)
	{
		return dp[n][r];
	}
	else
	{
		return dp[n][r] = min((int)1e9, combination(n - 1, r - 1) + combination(n - 1, r));
	}
}

void query(int n, int m, int k, string s)
{
	if (n + m == 0)
	{
		cout << s << endl;
		return;
	}
	else if (n == 0)
	{
		s.append("a");
		query(n - 1, m, k, s);
	}
	else
	{
		int leftCount = combination(n + m - 1, m);
		if (leftCount >= k)
		{
			s.append("a");
			query(n - 1, m, k, s);
		}
		else
		{
			s.append("z");
			query(n, m - 1, k - leftCount, s);
		}
	}
}

int main(void)
{
	init();
	cin >> N >> M >> K;
	int str_size = N + M;

	dp[0][0] = 1;
	query(N, M, K, "");

	return 0;
}