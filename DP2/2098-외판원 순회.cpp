#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 16
#define INF 1e9
using namespace std;

int N;
int dist[MAX][MAX];
int dp[MAX][1<<16];

int TSP(int now, int visited) 
{
	// N= 16 : 1 << N�� �ϸ� 0000 0000 0000 0001(2^1) �������� 16�� shift => 0001 0000 0000 0000 0000(2^16)
	// (1 << N) - 1�� �ϸ� 0001 0000 0000 0000 0000 - 0000 0000 0000 0001 = 1111 1111 1111 1111(2^16-1)

	// ��� �湮�Ͽ��ٸ�!!
	if (visited == (1 << N) - 1)
	{
		// �̹� �湮���� ������
		if (dist[now][0] != 0) return dist[now][0];
		return INF;
	}
	// �̹� ���� ���
	if (dp[now][visited] != 0) return dp[now][visited];
	dp[now][visited] = INF;
	
	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next)) continue; // �̹� �湮 �� ���̶�� pass
		if (dist[now][next] == 0) continue; // ���� ���� ��� pass
		dp[now][visited] = min(dp[now][visited], dist[now][next] + TSP(next, visited | (1 << next)));
	}

	return dp[now][visited];
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> dist[i][j];
		}
	}		

	cout << TSP(0, 1) << endl;

	return 0;
}