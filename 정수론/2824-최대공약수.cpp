#include <bits/stdc++.h>
#define ft first
#define sd second
const int MOD = 1'000'000'000;

using namespace std;
using ll = long long;

bool isBig = false;
int n, m;
map<ll, int> a, b;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	cin >> n;
	ll x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = 2; j * j <= x; j++) 
		{
			while (x % j == 0)
			
			{
				a[j]++;
				x /= j;
			}
		}
		if (x > 1) a[x]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;

		for (int j = 2; j * j <= x; j++)
		{
			while (x % j == 0) 
			{
				b[j]++;
				x /= j;
			}
		}

		if (x > 1) b[x]++;
	}

	auto pa = a.begin(), pb = b.begin();
	ll ans = 1;

	while (pa != a.end() && pb != b.end())
	{
		if (pa->ft > pb->ft) 
		{
			pb++;
		}
		else if (pa->ft < pb->ft)
		{
			pa++;
		}
		else
		{
			int cnt = min(pa->sd, pb->sd);
			while (cnt--) 
			{
				ans *= pa->ft;

				if (ans >= MOD) 
				{
					isBig = true;
					ans %= MOD;
				}
			}
			pa++;
			pb++;
		}
	}

	if (isBig) 
	{
		cout.width(9);
		cout.fill('0');
	}

	cout << ans;
}