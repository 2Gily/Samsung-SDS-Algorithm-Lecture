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
	1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
	3. 마지막 도착 계단은 반드시 밟아야 한다.
	각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.
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
		// 3칸을 연속으로 못가는 조건을 따져서 만들어야함.
		// ㅁㅁㅁㅁ 4개의 개단을 한 묶음으로 보면
		// OXOO OOXO XOXO 3가지 방법이 나옴
		// 요약 OXOO ?OXO =? ?의 경우 dp에 저장되어 있는 값을 이용 이건 밟아도 되고 안밟아도 되니까
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
	}

	cout << dp[n] << endl;

	return 0;
}