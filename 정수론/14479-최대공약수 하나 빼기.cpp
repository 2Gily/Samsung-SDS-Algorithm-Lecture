#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
const int MAX = 1000001;
using namespace std;

int N;
int number[MAX];
int LtoR[MAX];
int RtoL[MAX];

// gcd(a,b) == gcd(b, a % b), stop when a % b == 0
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
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

	for (int i = 0; i < N; i++) cin >> number[i];

	LtoR[0] = number[0];
	RtoL[N - 1] = number[N - 1];

	// 누적 최대공약수 구하기 LtoR -> 1~R 까지의 누적GCD, RtoL -> L~(N-1)
	for (int i = 1; i < N; i++)
	{
		LtoR[i] = gcd(LtoR[i - 1], number[i]);
		RtoL[N - 1 - i] = gcd(RtoL[N - i], number[N - 1 - i]);
	}

	int max_gcd = 0;
	int target_number = -1;

	if (max_gcd < RtoL[1])
	{
		max_gcd = RtoL[1];
		target_number = number[0];
	}

	// [a][][]
	// [][][c] 이런방식으로 구하기!
	for (int i = 1; i < N - 1; i++)
	{
		int temp = gcd(LtoR[i - 1], RtoL[i + 1]);
		if (max_gcd < temp)
		{
			max_gcd = temp;
			target_number = number[i];
		}
	}

	if (max_gcd < LtoR[N - 1]) 
	{
		max_gcd = LtoR[N - 2];
		target_number = number[N - 1];
	}

	if (target_number % max_gcd == 0) cout << -1 << endl;
	else cout << max_gcd << " " << target_number << endl;
	
	return 0;
}