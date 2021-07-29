#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 51

using namespace std;

typedef struct LOCATION {
	int y;
	int x;
}LOCATION;

char map[MAX][MAX]; // . : ºó °ø°£, X : µ¹, S : °í½¿µµÄ¡, D : µ¿±¼
bool visit[MAX][MAX]; // ¹æ¹®Ã¼Å©
LOCATION finished;
int Y, X;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
queue<LOCATION> water;
queue<LOCATION> animal;

void BFS()
{
	int time = 0;

	while(!animal.empty()) 
	{
		time++;
		int water_size = water.size();

		while (water_size--) 
		{
			int y = water.front().y;
			int x = water.front().x;
			water.pop();

			for (int i = 0; i < 4; i++) 
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if ( ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
				if (map[ny][nx] == 'X' || map[ny][nx] == 'D' || map[ny][nx] == '*') continue;
				water.push({ ny, nx });
				map[ny][nx] = '*';
			}
		}

		int animal_size = animal.size();

		while (animal_size--)
		{
			int y = animal.front().y;
			int x = animal.front().x;
			animal.pop();

			visit[x][y] = true;

			if (y == finished.y && x == finished.x) 
			{
				cout << time - 1 << endl;
				return;
			}

			for (int i = 0; i < 4; i++) 
			{
				int ny = x + dy[i];
				int nx = y + dx[i];

				if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
				if (map[ny][nx] == 'X' || map[ny][nx] == '*' || visit[ny][nx]) continue;

				visit[ny][nx] = true;
				animal.push({ ny, nx });
			}
		}
	}
	cout << "KAKTUS" << endl;
	return;
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

	cin >> Y >> X;

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '*')
			{
				water.push({ i,j });
			}
			else if (map[i][j] == 'S')
			{
				animal.push({ i,j });
			}
			else if (map[i][j] == 'D')
			{
				finished.y = i;
				finished.x = j;
			}
		}
	}

	BFS();

	return 0;
}