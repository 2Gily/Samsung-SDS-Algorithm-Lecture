#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 501
using namespace std;

int N; 
int inDegree[MAX];
int duration[MAX]; 
int result[MAX]; 
vector<int> graph[MAX];

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

	// 1. input data 입력 받기.
	for (int i = 1; i <= N; i++)
	{	
		// 1-1. time(value) 입력 받기.
		cin >> duration[i];
		
		while (1)
		{
			// 1-2. -1 나오기 전까지 입력받기.
			int node;
			cin >> node;
			if (node == -1) break; 
			
			inDegree[i]++; // i번 노드 진입차수(inDegree) +1 하기
			graph[node].push_back(i); // i번 노드의 진입노드 추가
		}
	}
	// 2. 위상정렬의 첫 재료 inDegree == 0 인 것 Queue에 넣어주기.
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0) q.push(i);
	}
	// 3. 위상정렬 실행 q.empty() 될 때 까지
	while (!q.empty())
	{
		// a. 선행 조건이 더 이상 없는 건물을 뽑아서 최종 건설시간에 자기 자신을 더해줌.
		int now = q.front();
		q.pop();
		// b. 자신을 지어야 지을 수 있는 건물들에게 선행 건물의 건설이 끝났음을 알림
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			// b-1. 선행 건물(진입차수)의 개수 빼주기
			inDegree[next]--;
			// b-2. 타겟 건물은 아직 건물을 지을 수 없는 상태
			// -> 현재 상태에서 타겟건물의 answer는 선행건물의 건설시간 중 최댓값.
			result[next] = max(result[next], result[now] + duration[now]);
			// b-3. 타겟 건물의 선행 건물 개수가 0이면 큐에 넣기.
			if (inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
	//4. 정답 출력
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] + duration[i] << endl;
	}

	return 0;
}