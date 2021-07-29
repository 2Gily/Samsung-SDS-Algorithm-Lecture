#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 100
using namespace std;

long long number[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();

	long long N;
	cin >> N;

	number[0] = 0;
	number[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		number[i] = number[i - 2] + number[i - 1];
	}

	cout << number[N] << endl;

	return 0;
}