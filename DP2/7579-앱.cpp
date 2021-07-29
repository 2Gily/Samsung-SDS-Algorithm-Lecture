#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M; // Ȱ��ȭ�� ���� ��, �޸� ����
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
	<�賶(Knapsack) ���� ����>

	�賶 ������ �ΰ����� �з��ȴ�.
	1. ������ �ɰ� �� �ִ� �賶����(Fraction Knapsack Problem)
	2. ������ �ɰ� �� ���� �賶����(0/1 Knapsack Problem)
	
	1. ������ �ɰ� �� �ִ� �賶������ ���� ��ġ�� ū ���Ǻ��� ���, ���� ���� ��ŭ ������ �ɰ��� ������� �׸��� �˰����� ���.
	2. ������ �ɰ� �� ���� �賶������ ���� ������ȹ���� ���.

	[��������]

	n�� ���ǰ���, k�� ������ �� �ִ� ���԰�
	w[]�� ���ǿ� ���� ���԰���
	v[]�� �ش� ���ǿ� ���� ��ġ��

	i�� i��° ���� j�� ���Ը� ��Ÿ.
	��, dp[i][j]�� i��° ���Ǳ��� �ִ� j���Ա��� �����Ҷ� �ְ��� ��ġ��.

	��ȭ����
	if(w[i]<=j) �϶���
	dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]
	else
	dp[i][j] = dp[i - 1][j]

	�� - ����
	�޸� - ����
	Ȱ��ȭ��� - ��ġ
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

	// dp[i][j] => i��°���� ��, ��Ȱ��ȭ�� �ʿ��� �ڿ��� �� j�� �ִ밪(100*100)
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