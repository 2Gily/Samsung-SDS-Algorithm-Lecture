#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1001
using namespace std;

int n, m;
int number[MAX][MAX];
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
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			number[i][j] = temp[j] - '0';
		}
	}

	int result = -1;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = number[i][j];
			}
			else if (number[i][j] == 1)
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}

			result = max(result, dp[i][j]);
		}
	}

	cout << result * result << endl;


	return 0;
}