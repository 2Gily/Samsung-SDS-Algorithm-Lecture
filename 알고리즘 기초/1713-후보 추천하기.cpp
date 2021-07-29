#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<int, pii> frame; // first = recommand count , second = waiting time

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int n, m;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int temp;
		cin >> temp;

		if (frame.find(temp) == frame.end()) // ���� �����ӿ� ������
		{
			if (frame.size() < n) // ����Ʋ�� ������� ������
			{
				frame[temp].first = 1;
				frame[temp].second = i;
			}
			else				// ����Ʋ�� ������� ������
			{
				int student = frame.begin()->first;
				pii value = frame.begin()->second;

				for (auto a : frame)
				{
					if (a.second < value)
					{
						student = a.first;
						value = a.second;
					}
				}

				frame.erase(student);
				frame[temp].first = 1;
				frame[temp].second = i;
			}
		}
		else // ���� �����ӿ� ������
		{
			frame[temp].first = frame[temp].first + 1;
		}
	}

	for (auto it : frame)
	{
		cout << it.first << " ";
	}

	return 0;
}