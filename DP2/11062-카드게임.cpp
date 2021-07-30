#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 1001

using namespace std;

int card[MAX];
int dp[2][MAX][MAX]; // [ 0 : 근우, 1: 명우][ 출발 ][ 도착 ]

// start : 가장 왼쪽의 index, end : 가장 오른 쪽의 index, [ true : 근우, false : 명우 ]
int choice(bool turn, int start, int last)
{
	int &result = dp[turn][start][last];

	if (result != -1) return result;
	// 마지막장 
	if (start == last) 
	{
		if (turn) return result = card[start];
		else return result = 0;		
	}
	// 근우 차례에서는 왼쪽, 오른쪽 중 하나 '취하고' 게임 진행 했을 때 '최대'값.
	if (turn)
	{
		return 	result = max(choice(false, start + 1, last) + card[start], choice(false, start, last - 1) + card[last]);
	}
	// 명우 차례에서는 왼쪽, 오른쪽 중 하나를 '없애고' 게임 진행 했을 때 '최소'값
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