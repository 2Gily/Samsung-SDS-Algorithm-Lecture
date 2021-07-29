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
	int num,i;
	cin >> num;

	for (i = 2; i * i <= num; i++)
	{
		while (num % i == 0)
		{
			cout << i << '\n';
			num /= i;
		}
	}

	if (num > 1)
	{
		cout << num;;
	}

	return 0;
}