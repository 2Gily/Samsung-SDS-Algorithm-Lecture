#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int GCD(int a, int b)
{
	while(b != 0)
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

	int a, A;
	int b, B;

	cin >> a >> A;
	cin >> b >> B;

	int aB = a * B;
	int Ab = A * b;
	int AB = A * B;

	if (aB + Ab == AB)
	{
		cout << 1 << " " << 1 << endl;
		return 0;
	}

	int gcd_number = GCD(max(aB + Ab, AB), min(aB + Ab, AB));

	cout << (aB + Ab) / gcd_number << " " << AB / gcd_number << endl;
	return 0;
}