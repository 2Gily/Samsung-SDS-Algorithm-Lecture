#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 4001

using namespace std;

string A, B;
int dp[MAX][MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> A >> B;

	A = "0" + A;
	B = "0" + B;
	int answer = 0;

	for (int i = 1; i < B.size(); i++)
	{
		for (int j = 1; j < A.size(); j++)
		{
			if (B[i] == A[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(dp[i][j], answer);
			}
		}
	}

	cout << answer << endl;

	return 0;
}