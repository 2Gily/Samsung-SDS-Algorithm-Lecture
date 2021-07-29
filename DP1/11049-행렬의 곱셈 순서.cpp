#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[510][2];
int dp[510][510];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	(Example - ��α� ����)
	20x1, 1x30, 30x10, 10x10

	((A*B)*C)*D) = (20*1*30) + (20*30*10) + (20*10*10) = 8,600
	A*(B*(C*D)) = (30*10*10) + (1*30*10) + (20*1*10) = 3,500
	(A*B)*(C*D) = (20*1*30) + (30*10*10) + (20*30*10) = 9,600
	(A*((B*C)*D) = (1*30*10) + (1*10*10) + (20*1*10) = 600

	DP : ū ������ ���� ������ �ɰ��鼭 Memoization�� ���� ������ �ذ��ϴ� �� �������!

	dp[i][j] => ���i���� ���j ������ ���� �� �ʿ��� ������ �ּ�Ƚ��
	dp[i][j] = dp[i][k] + dp[k+1][j] + ���� ��� �� �ּڰ�.

	*/
	init();
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i < n; i++)
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= n; m++)
	{
		for (int i = 1; i <= n - m; i++)
		{
			int j = i + m;
			/*
			123 234 345 456 ... �̷������� ���� ������ ����� �� �� �ּҰ��� ���ذ��鼭 ĳ��
			*/
			for (int k = i; k < j; k++)
			{
				int result = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (!dp[i][j] || dp[i][j] > result) dp[i][j] = result;
			}
		}
	}
	cout << dp[1][n];

	return 0;
}