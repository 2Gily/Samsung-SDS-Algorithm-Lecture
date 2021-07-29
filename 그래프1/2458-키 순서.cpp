#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 501
#define INF 1e9
using namespace std;

int N, M; // N : �л��� ��, M : ������ ��
vector<vector<int>> dist;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	cin >> N >> M;
	dist.resize(N + 1, vector<int>(N + 1));

	// 1. 2���� �迭�� INF (�ִ�)���� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = INF;
		}
	}
	// 2. �Է� : a - b �л��� Ű ������ �ƴ� ��� 1�� �Ÿ� �迭 �Է�
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
	}
	// 3. Ư�� �л��� ��� �л����� �Ÿ��� üũ�ؾ��ϹǷ� �÷��̵� ���� ����
	// �÷��̵�-���� : ������ - ����� - ������ 3�� for��
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
	// 4. ��� �л����� �񱳰� ������ ���
	//    �� �Ÿ��� INF �� �ƴ� �л��� ���� N-1�� ��� : Ű�� ���°���� �� �� �����Ƿ� ans++ 
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] != INF || dist[j][i] != INF) cnt++;

		}
		if (cnt == N - 1) answer++;
	}

	cout << answer << endl;

	return 0;
}