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
	// 1. 목표하는 수리된 발전수의 개수가 만족한다면
	if (cnt >= P) return 0;
	// 2. 이미 계산했던 경우
	if (dp[cnt][visited] != -1) return dp[cnt][visited];

	dp[cnt][visited] = INF;

	// 3. 반복문 돌면서 재귀탐색
	for (int i = 0; i < N; i++) 
	{
		// 3-1. 발전소가 켜져 있는 경우
		if ((visited & (1 << i)) != 0)
		{
			for (int j = 0; j < N; j++)
			{
				// 3-1-a. 같은 번호의 발전소인 경우(자기 자신) contitnue
				if (i == j) continue;
				// 3-1-b. 앞으로 방문할 장소인 j도 켜져있는 경우 continue
				if ((visited & (1 << j)) != 0) continue;
				// 최소값 구하기
				dp[cnt][visited] = min(dp[cnt][visited], cost[i][j] + DFS(cnt + 1, visited | (1 << j)));
			}
		}
	}

	return dp[cnt][visited];
}

int main(void)
{
	// 뭔가 N이 16이하로 주어지면 TSP(외판원 순회) + BitMask를 생각하면 되겠다.
	// 적어도 P개의 발전소가 고장나 있지 않도록, 발전소를 고치는 비용의 최솟값을 구하는 프로그램을 작성하시오.
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
			// 현재 on되어 있는 곳은 방문 안해도 되니까,
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