#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 300000

using namespace std;

int N, K;
int bag[MAX];
pair<int, int> jewelry[MAX];
priority_queue<int> pq; //maxHeap ���

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	//���� ���� ���� ����

	//���� ���Լ� ����
	//���� ������ ���� ��

	//1. ���� ���� �� ���� ���� ������ ���� <- ����
	//2. ���õ� ���濡 ���� �� �մ� ���� ���� �� ���� ��� ������ ���� <- ���� ���

	init();
	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> jewelry[i].first >> jewelry[i].second;
	for (int i = 0; i < K; i++) cin >> bag[i];

	//����(���� ����)�� ���� �������� ����
	sort(jewelry, jewelry + N);
	sort(bag, bag + K);

	long long result = 0;
	int idx = 0;

	//���������� ���� ������� �ִ��� ��� ������ �ִ� ���
	for (int i = 0; i < K; i++)
	{
		//i ��° ������ �������ѿ� �����ϴ� ���� �� ����
		while (idx < N && jewelry[idx].first <= bag[i])
		{
			pq.push(jewelry[idx++].second);
		}

		//pq�� ��Ʈ���� ���� ���� ���� ��� ������ �������
		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << "\n";

	return 0;
}