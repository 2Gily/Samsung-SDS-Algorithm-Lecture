#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<string> word;
int result;
int alphabet[26];

void greedy(void)
{
	for (int i = 0; i < word.size(); i++)
	{
		int pow = 1;

		for (int j = word[i].size() - 1; j >= 0; j--)
		{
			int idx = word[i][j] - 'A';
			alphabet[idx] += pow;
			pow *= 10;
		}
	}

	sort(alphabet, alphabet + 26);

	int num = 9;

	for (int i = 25; i >= 0; i--)
	{
		if (alphabet[i] == 0) break;
		result += (alphabet[i] * num);
		num--;
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

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		word.push_back(temp);
	}

	greedy();
	cout << result << endl;

	return 0;
}