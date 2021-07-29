#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
int t;
ll gcd(ll a, ll b) 
{
	if (a < b)return gcd(b, a);
	else if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() 
{
	cin >> t;
	while (t--) 
	{
		string s;
		cin >> s;
		int b = 0, nb = 0;
		s.erase(0, 2);
		bool k = false;
		for (auto i : s) 
		{
			if (k && i != ')') b++;
			else if (i == '(') k = true;
			else if (i != ')' && i != '(')nb++;
		}

		for (int i = 0; s[i]; i++) 
		{
			if (s[i] == '(') 
			{
				s.pop_back();
				s.erase(s.begin() + i);
				break;
			}
		}
		if (b == 0) 
		{
			ll x = stoll(s), y = (ll)pow(10, nb);
			ll g = gcd(x, y);
			cout << x / g << '/' << y / g << '\n';
		}
		else 
		{
			string y;
			ll x = 0;
			for (int i = 0; i < b; i++)y += "9";
			for (int i = 0; i < nb; i++)y += "0";
			if (nb == 0) x = stoll(s);
			else x = stoll(s) - stoll(s.substr(0, nb));
			ll yy = stoll(y);
			ll g = gcd(x, yy);
			cout << x / g << '/' << yy / g << '\n';
		}
	}
	return 0;
}