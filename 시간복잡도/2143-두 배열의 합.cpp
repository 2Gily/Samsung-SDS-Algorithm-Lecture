#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int T, N, M, temp;
ll cnt;
vector<long long> A;
vector<long long> B;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();

	cin >> T;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		B.push_back(temp);
	}

	for (int i = 0; i < N - 1; i++)
	{
		long long sum = A[i];

		for (int j = i + 1; j < N; j++)
		{
			sum += A[j];
			A.push_back(sum);
		}

	}

	for (int i = 0; i < M - 1; i++)
	{
		long long sum = B[i];
		for (int j = i + 1; j < M; j++)
		{
			sum += B[j];
			B.push_back(sum);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<long long>());

	ll a = 0, b = 0;

	while (a < A.size() && b < B.size())
	{
		if (A[a] + B[b] < T)
		{
			a++;
		}
		else if (A[a] + B[b] == T) //ÇÕ ÀÏÄ¡
		{
			ll a_count = 1, b_count = 1;
			int i;

			for (i = a + 1; i < A.size(); i++)
			{
				if (A[i] == A[a]) a_count++;
				else break;
			}

			a = i;

			for (i = b + 1; i < B.size(); i++)
			{
				if (B[i] == B[b]) b_count++;
				else break;
			}

			b = i;
			cnt += (a_count * b_count);

		}
		else if (A[a] + B[b] > T)
		{
			b++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
