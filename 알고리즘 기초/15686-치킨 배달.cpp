#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"
#define MAX 50
#define INF INT_MAX
using namespace std;
typedef pair<int, int> PAIR;

int n, m;
int map[MAX][MAX];
int answer;
vector<PAIR> home;
vector<PAIR> chicken;
bool visit[13];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int distance(PAIR a, PAIR b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int index, int open)
{
	if (open == m)
	{
		int temp = 0;

		for (int i = 0; i < home.size(); i++)
		{
			int dist = INF;

			for (int j = 0; j < chicken.size(); j++)
			{
				if (visit[j]) dist = min(dist, distance(home[i], chicken[j]));

			}
			temp += dist;
		}

		answer = min(answer, temp);
		return;
	}

	if (index == chicken.size()) return;

	visit[index] = true;
	dfs(index + 1, open + 1);
	visit[index] = false;
	dfs(index + 1, open);
}

int main(void)
{
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) home.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	answer = INF;
	dfs(0, 0);
	cout << answer << endl;

	return 0;
}