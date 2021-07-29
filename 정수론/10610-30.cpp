#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

bool zero_check(string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == '0') return false;
	}

	return true;
}

bool three_check(string number)
{
	int position_sum = 0;

	for (int i = 0; i < number.size(); i++)
	{
		position_sum += number[i] - '0';
	}

	if (position_sum % 3 == 0) return false;
	else return true;
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
	string number;
	cin >> number;

	if (zero_check(number) || three_check(number))
	{
		cout << -1 << endl;
		return 0;
	}

	sort(number.begin(), number.end(), greater<char>());
	cout << number << endl;

	return 0;
}