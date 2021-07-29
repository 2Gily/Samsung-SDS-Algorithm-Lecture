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

	// 1. input data �Է� �ޱ�.
	for (int i = 1; i <= N; i++)
	{	
		// 1-1. time(value) �Է� �ޱ�.
		cin >> duration[i];
		
		while (1)
		{
			// 1-2. -1 ������ ������ �Է¹ޱ�.
			int node;
			cin >> node;
			if (node == -1) break; 
			
			inDegree[i]++; // i�� ��� ��������(inDegree) +1 �ϱ�
			graph[node].push_back(i); // i�� ����� ���Գ�� �߰�
		}
	}
	// 2. ���������� ù ��� inDegree == 0 �� �� Queue�� �־��ֱ�.
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0) q.push(i);
	}
	// 3. �������� ���� q.empty() �� �� ����
	while (!q.empty())
	{
		// a. ���� ������ �� �̻� ���� �ǹ��� �̾Ƽ� ���� �Ǽ��ð��� �ڱ� �ڽ��� ������.
		int now = q.front();
		q.pop();
		// b. �ڽ��� ����� ���� �� �ִ� �ǹ��鿡�� ���� �ǹ��� �Ǽ��� �������� �˸�
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			// b-1. ���� �ǹ�(��������)�� ���� ���ֱ�
			inDegree[next]--;
			// b-2. Ÿ�� �ǹ��� ���� �ǹ��� ���� �� ���� ����
			// -> ���� ���¿��� Ÿ�ٰǹ��� answer�� ����ǹ��� �Ǽ��ð� �� �ִ�.
			result[next] = max(result[next], result[now] + duration[now]);
			// b-3. Ÿ�� �ǹ��� ���� �ǹ� ������ 0�̸� ť�� �ֱ�.
			if (inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
	//4. ���� ���
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] + duration[i] << endl;
	}

	return 0;
}