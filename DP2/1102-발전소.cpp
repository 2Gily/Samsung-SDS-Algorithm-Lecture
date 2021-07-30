#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 16
#define INF 1e9
using namespace std;

int N,P;
int cost[MAX][MAX];
int dp[MAX][1 << MAX];
int onMask;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int DFS(int cnt, int visited)
{
	//cout << "visited "<< visited << " cnt " << cnt << endl;
	// 1. ��ǥ�ϴ� ������ �������� ������ �����Ѵٸ�
	if (cnt >= P) return 0;
	// 2. �̹� ����ߴ� ���
	if (dp[cnt][visited] != -1) return dp[cnt][visited];

	dp[cnt][visited] = INF;

	// 3. �ݺ��� ���鼭 ���Ž��
	for (int i = 0; i < N; i++) 
	{
		// 3-1. �����Ұ� ���� �ִ� ���
		if ((visited & (1 << i)) != 0)
		{
			for (int j = 0; j < N; j++)
			{
				// 3-1-a. ���� ��ȣ�� �������� ���(�ڱ� �ڽ�) contitnue
				if (i == j) continue;
				// 3-1-b. ������ �湮�� ����� j�� �����ִ� ��� continue
				if ((visited & (1 << j)) != 0) continue;
				// �ּҰ� ���ϱ�
				dp[cnt][visited] = min(dp[cnt][visited], cost[i][j] + DFS(cnt + 1, visited | (1 << j)));
			}
		}
	}

	return dp[cnt][visited];
}

int main(void)
{
	// ���� N�� 16���Ϸ� �־����� TSP(���ǿ� ��ȸ) + BitMask�� �����ϸ� �ǰڴ�.
	// ��� P���� �����Ұ� ���峪 ���� �ʵ���, �����Ҹ� ��ġ�� ����� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	init();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	int on_cnt = 0;
	string temp;
	cin >> temp;

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 'Y')
		{
			// ���� on�Ǿ� �ִ� ���� �湮 ���ص� �Ǵϱ�,
			onMask = onMask | (1 << i);
			on_cnt++;
		}
	}
	cin >> P;
	if (P == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int answer = DFS(on_cnt, onMask);

	if (answer == -1 || on_cnt == 0) cout << -1 << endl;
	else cout << answer << endl;
	
	return 0;
}