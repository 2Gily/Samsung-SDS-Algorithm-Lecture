#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 31
#define INF 1e9
using namespace std;

typedef struct GHOST {
	int x1,y1;
	int x1,y2;
	int time;
}GHOST;

typedef struct INFO {
	int x, y;
}INFO;

int W, H, G, E; // �ʺ�(��), ����(��), ������ ����, �ͽ� ������ ��
vector<vector<int>> dist;
INFO start,goal;
INFO mv[4] = { {0,1},{1,0},{0,-1},{-1,0} }; // �ð� ���� : ��,��,��,��
vector<GHOST> ghost;
vector<INFO> grave;

void init_value(void)
{
	 
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
	while (1)
	{
		// a. W == 0 AND H == 0�� ���� �� ���� �ݺ�
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		// 1.���� ���� �׽�Ʈ ���̽� �ʱ�ȭ
		start = { 0,0 };
		goal = { W - 1,H - 1 };
		ghost.clear();
		grave.clear();
		dist.clear();
		dist.resize(H, vector<int>(W, 0));
		// b. ���� {x,y} ��ǥ �� E�� �Է� �ޱ�
		cin >> E;
		for (int i = 0; i < E; i++)
		{
			int x, y;
			cin >> x >> y;
			grave.push_back({ x,y });
		}
		// c. �ͽ� ���� {x1,y1} -> {x2,y2} �Է�, �̵��ϴ� �ð� time �Է� �ޱ�
		cin >> G;
		for (int i = 0; i < G; i++)
		{
			int x1, y1, x2, y2, time;
			cin >> x1 >> y1 >> x2 >> y2 >> time;
			ghost.push_back({ x1,y1,x2,y2,time });
		}
	}


	return 0;
}