#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl "\n"
#define MAX 50
using namespace std;

int N;
int house;
char map[MAX][MAX];
int height[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> sd; // SangDuk¿« <y,x>
int dy[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int dx[] = { 0, 1, 1, 1, 0,-1,-1,-1};

bool BFS(int left, int right)
{
	queue<pair<int, int>> q;
	q.push({ sd.first,sd.second });
	visited[sd.first][sd.second] = true;
	int temp = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == 'K')
		{
			temp++;
			if (temp == house) return true;
		}
		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (visited[ny][nx]) continue;
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(height[ny][nx] < left || height[ny][nx] > right) continue;

			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	return false;
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

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		
		for (int j = 0; j < N; j++)
		{
			map[i][j] = temp[j];

			if (map[i][j] == 'P')
			{
				sd.first = i;
				sd.second = j;
			}
			else if (map[i][j] == 'K')
			{
				house++;
			}
		}
	}

	vector<int> height_gap;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> height[i][j];
			height_gap.push_back(height[i][j]);
		}
	}

	sort(height_gap.begin(), height_gap.end());
	height_gap.erase(unique(height_gap.begin(), height_gap.end()), height_gap.end());

	int answer = 2e9;
	int left = 0, right = 0;

	while (right < height_gap.size())
	{
		while (true)
		{
			bool check = false;
			
			if (height_gap[left] <= height[sd.first][sd.second] && height[sd.first][sd.second] <= height_gap[right])
			{
				check = BFS(height_gap[left], height_gap[right]);
				memset(visited, false, sizeof(visited));
			}

			if (check == false) break;

			int diff = height_gap[right] - height_gap[left];
			if (answer > diff) answer = diff;
			left++;
		}
		right++;
	}

	cout << answer << endl;

	return 0;
}