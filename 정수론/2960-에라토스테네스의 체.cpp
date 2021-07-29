#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1001
using namespace std;

int N, K,cnt;
bool number[MAX];

int eratos(void)
{
	number[0] = true;
	number[1] = true;

	for (int i = 2; i <= N; i++)
	{
		if (number[i]) continue;

		number[i] = true;
		cnt++;

		if (cnt == K) return i;

		for (int j = i + i ; j <= N; j += i) 
		{
			if (number[j]) continue;

			number[j] = true;
			cnt++;

			if (cnt == K) return j;
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
	cin >> N >> K;
	cout << eratos();

	return 0;
}