#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 301
using namespace std;

int n, sum;
int stair[MAX];
long long dp[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	1. ����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
	2. ���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
	3. ������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
	�� ��ܿ� ���� �ִ� ������ �־��� �� �� ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/
	init();
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
		sum += stair[i];
	}

	dp[1] = stair[1];
	dp[2] = dp[1]+stair[2];

	for (int i = 3; i <= n; i++)
	{
		// 3ĭ�� �������� ������ ������ ������ ��������.
		// �������� 4���� ������ �� �������� ����
		// OXOO OOXO XOXO 3���� ����� ����
		// ��� OXOO ?OXO =? ?�� ��� dp�� ����Ǿ� �ִ� ���� �̿� �̰� ��Ƶ� �ǰ� �ȹ�Ƶ� �Ǵϱ�
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	cout << dp[n] << endl;

	return 0;
}