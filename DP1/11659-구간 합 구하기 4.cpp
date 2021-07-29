#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 100001

using namespace std;

int N, M;
int number[MAX];
long long memo[MAX];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> number[i];

	memo[1] = number[1];
	for (int i = 2; i <= N; i++)
	{
		memo[i] = memo[i - 1] + number[i];
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << memo[b] - memo[a - 1] << endl;
	}

	return 0;
}