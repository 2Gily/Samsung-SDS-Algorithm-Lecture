#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	int n;
	int maxDP[3] = { 0,0,0 };
	int minDP[3] = { 0,0,0 };
	int input[3];
	int temp_0, temp_2;

	cin >> n;
	cin >> maxDP[0] >> maxDP[1] >> maxDP[2];

	minDP[0] = maxDP[0]; 
	minDP[1] = maxDP[1]; 
	minDP[2] = maxDP[2];

	for (int i = 1; i < n; i++) 
	{
		cin >> input[0] >> input[1] >> input[2];

		//최대값을 구해주는 DP배열 
		temp_0 = maxDP[0]; 
		temp_2 = maxDP[2];
		maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
		maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
		maxDP[1] = max({ temp_0, maxDP[1], temp_2 }) + input[1];

		//최소값을 구해주는 DP배열
		temp_0 = minDP[0]; 
		temp_2 = minDP[2];
		minDP[0] = min(minDP[0], minDP[1]) + input[0];
		minDP[2] = min(minDP[1], minDP[2]) + input[2];
		minDP[1] = min({ temp_0, minDP[1], temp_2 }) + input[1];
	}

	cout << max({ maxDP[0],maxDP[1],maxDP[2] }) << " " << min({ minDP[0],minDP[1],minDP[2] });

	return 0;
}

