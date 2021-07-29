#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1000001
using namespace std;

bool prime[MAX];

void eratos(void)
{
	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i]) continue;

		for (int j = i + i; j <= MAX; j += i)
		{
			if (prime[j]) continue;
			else prime[j] = true;
		}
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
	eratos();
	while (true)
	{
		int number;
		cin >> number;

		if (number == 0) break;

		for (int i = number; i >= 0; i--)
		{
			if (!prime[i] && !prime[number-i])
			{
				cout << number << " = " << number - i << " + " << i << endl;
				break;
			}
		}
	}

	return 0;
}