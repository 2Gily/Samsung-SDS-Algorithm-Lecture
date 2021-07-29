#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 1000001

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

	int N, M;
	cin >> N >> M;
	
	vector<long long> wood(N);
	for (int i = 0; i < N; i++) cin >> wood[i];

	sort(wood.begin(), wood.end());

	long long up = *max_element(wood.begin(), wood.end());
	long long down = 0;
	long long mid = 0;
	long long result = 0;

	while (down <= up)
	{
		mid = (up + down) / 2;
		long long sum = 0;
		
		for (int i = 0; i < N; i++) if (wood[i] - mid > 0) sum += (wood[i] - mid);

		if (sum >= M)
		{
			result = max(result, mid);
			down = mid + 1;
		}
		else
		{
			up = mid - 1;
		}
	}

	cout << result << endl;

	return 0;
}