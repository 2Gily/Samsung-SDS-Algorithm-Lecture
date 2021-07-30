#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 1001

using namespace std;

int card[MAX];
int dp[2][MAX][MAX]; // [ 0 : �ٿ�, 1: ���][ ��� ][ ���� ]

// start : ���� ������ index, end : ���� ���� ���� index, [ true : �ٿ�, false : ��� ]
int choice(bool turn, int start, int last)
{
	int &result = dp[turn][start][last];

	if (result != -1) return result;
	// �������� 
	if (start == last) 
	{
		if (turn) return result = card[start];
		else return result = 0;		
	}
	// �ٿ� ���ʿ����� ����, ������ �� �ϳ� '���ϰ�' ���� ���� ���� �� '�ִ�'��.
	if (turn)
	{
		return 	result = max(choice(false, start + 1, last) + card[start], choice(false, start, last - 1) + card[last]);
	}
	// ��� ���ʿ����� ����, ������ �� �ϳ��� '���ְ�' ���� ���� ���� �� '�ּ�'��
	else
	{
		return result = min(choice(true, start + 1, last), choice(true, start, last - 1));
	}
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
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int N;
		cin >> N;

		memset(dp, -1, sizeof(dp));
		memset(card, 0, sizeof(card));

		for (int i = 0; i < N; i++)
		{
			cin >> card[i];
		}

		cout << choice(true,0, N - 1) << endl;
	}

	return 0;
}