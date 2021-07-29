#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1000000000
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
	long long total, win, rate;
	cin >> total >> win;

	rate = (100 * win) / total;

	if (rate >= 99)
	{
		cout << -1 << endl;
		return 0;
	}

	long long low = 0, high = MAX, mid, result_rate;

	while (low <= high)
	{
		mid = (low + high) / 2;

		result_rate = ((win + mid) * 100) / (total + mid);

		if (rate < result_rate)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << low << endl;

	return 0;
}