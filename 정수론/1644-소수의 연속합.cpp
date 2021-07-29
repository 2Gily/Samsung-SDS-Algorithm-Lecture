#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<int> prime;
vector<bool> check;

void MakePrime(void)
{
	check[0] = check[1] = false;

	for (int i = 2; i * i <= N; i++)
	{
		if (!check[i]) continue;

		for (int j = i * i; j <= N; j += i)
		{
			check[j] = false;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (check[i]) prime.push_back(i);
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
	cin >> N;

	check.resize(N + 1, true);

	MakePrime();

	int answer = 0;
	int sum = 0;
	int low = 0, high = 0;

	while (high < prime.size())
	{
		if (sum >= N)
		{
			sum -= prime[low++];
		}
		else if (high == prime.size())
		{
			break;
		}
		else
		{
			sum += prime[high++];
		}

		if (sum == N) answer++;
	}

	cout << answer << endl;

	return 0;
}