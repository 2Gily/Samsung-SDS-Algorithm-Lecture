#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

int T;

typedef struct EGresult{
	long long s;
	long long t;
	long long r;
}EGresult;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = a;
	}
	return a;
}

EGresult ExtendedGcd(long long a, long long b)
{
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;

	long long temp;
	while (r1 != 0)
	{
		long long q = r0 / r1;

		temp = r0 - (r1 * q);
		r0 = r1;
		r1 = temp;

		temp = s0 - (s1 * q);
		s0 = s1;
		s1 = temp;

		temp = t0 - (t1 * q);
		t0 = t1;
		t1 = temp;
	}

	return { s0,t0,r0 };
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
	cin >> T;

	// X : 인당 나눠줄 사탕의 수
	// Y : 사탕 봉지의 수
	// Ax + 1 = By
	// Ax + By = C의 형태로 변환.
	// -Ax + By = 1
	// A(-x) +By = 1의 형태로 변환.

	while (T--)
	{
		// D = gcd(A,B)
		// Ax + By = C 일 때, C % D == 0 이어야 해를 가질 수 있음 : 베주 항등식
		// 이 문제에서 사람들 중 한명은 반드시 사탕을 잃어 버리기 때문에 
		// 전체 K의 수에서 + 1 을 해줬기 때문, 최소 1 이상이 되어야 해서  gcd(C,K) == 1로 해주었다.
		long long A, B;
		cin >> A >> B;

		if (A == 1 && B == 1)
		{
			cout << 2 << endl;
			continue;
		}
		if (B == 1)
		{
			if (A + 1 > 1e9) cout << "IMPOSSIBLE" << endl;
			else cout << A + 1 << endl;

			continue;
		}
		if (A == 1)
		{
			cout << 1 << endl;
			continue;
		}

		EGresult result = ExtendedGcd(A, B);

		if (result.r != 1)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		else
		{
			// x0 = s * C/D
			long long x0 = result.s;
			// y0 = t * C/D
			long long y0 = result.t;
			// x = x0 + B/D * k
			// y = y0 - A/D * k

			// x < 0
			// x + B * k < 0
			// k < -x / B
			// 0 < y <= 1e9
			// 0 < y - A * k < 1e9
			// - y < -A * k < 1e9 - y

			// (y - 1e9 / A) < k <  y / A
			//				   k < -x / B

			long long kFromY = (long long)ceil((double)y0 / (double)A) - 1;
			long long kFromX = (long long)ceil((double)-x0 / (double)B)- 1;
			long long k = min(kFromY, kFromX);
			long long y = y0 - (A * k);

			if (y <= 1e9)
			{
				cout << y << endl;
			}
			else
			{
				cout << "IMPOSSIBLE" << endl;
			}
		}
	}

	return 0;
}