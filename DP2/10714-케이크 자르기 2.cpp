#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int N;
int *cake;
long long **dp;

// �Լ�����ΰ� �־����, �ĺ��� ���� �߻�.
long long IOI(int , int );
long long JOI(int , int );

int goLeft(int idx)
{
	return (N + idx - 1) % N;
}

int goRight(int idx)
{
	return (idx + 1) % N;
}

long long IOI(int left, int right)
{
	// 1. ���� ������ ������
	if (goRight(right) == left)
	{
		return 0;
	}
	// 2. ������ �� ũ�� ��������, �ƴϸ� ����������
	if (cake[goLeft(left)] > cake[goRight(right)])
	{
		return JOI(goLeft(left), right);
	}
	return JOI(left, goRight(right));
}

long long JOI(int left, int right)
{
	// ���� ����
	if (goRight(right) == left) return dp[left][right] = 0;
	// ���� ���� 2
	if (dp[left][right] != -1) return dp[left][right]; 

	//left / right ��������� �Ѹ� �� ��ħ.
	long long leftV = cake[goLeft(left)] + IOI(goLeft(left), right);
	long long rightV = cake[goRight(right)] + IOI(left, goRight(right));

	return dp[left][right] = max(leftV, rightV);
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	[���� ����]
	- ���� :  1���� N ���� �ݽð�������� ��ȣ
	- 0��°�� N ��°, N + 1 ��°�� 1��°�� �����Ѵ�. ����(Cycle)
	- i ��° ������ ũ��� A[i]
	1. ����, JOI ���� N ���� ���� �� ���ϴ� �� �ϳ��� ��������.
	2. �����ư��� ���� ������ �ϳ��� ��������. ��, ������ ���� �� �ϳ� �̻��� ������ �̹� ���õ� ��쿡�� ������ �� �ִ�. 
	������ �� �ִ� ������ ���� �� ���� ����, IOI ���� �� �� ���� ū ������ ��������, JOI ���� ���ϴ� ������ ������ �� �ִ�.
	
	���� = > JOI ������ ������ ũ���� �ִ��D(MAX_SUM)
	*/

	/*
	[�� ����]
	dp[i][j][k] -> ī�� ������ ���������� �� ���� ������� ����ũ�� ������ ���� ������ ����
	i : 0 : J��, 1 : I ��, j : left, k : right
	����Ž�� -> ���� ���� -> ���� : ȯ��(Cycle) -> moduler �����ڸ� �̿��ؼ� ȯ������ 
	�������� -> left == right
	*/

	/*
	[�ʱ�]
	- ī�� ���Ӱ� ���
	- 2���� ����
		1. �������� / 1�� �Լ����� falg ������ �ص� ��.
		2. 2�� �Լ� JOI, IOI ������
	- JOI ���� ũ�� ���� �ִ�ȭ
	- JOI ���� ����

	- 1 ~ N : ȯ��, ��ȯ��
	  0��° : N, 1���� : 1(N + 1)

	  int goRight(int idx)
	  {
		return (idx + 1) % N;
	  }
	  int goLeft(int idx)
	  {
		return (N + idx - 1) % N;
	  }
	*/

	init();
	cin >> N;

	cake = new int[N + 1];

	for (int i = 0; i < N; i++) 
	{
		cin >> cake[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> cake[i];
	}

	dp = new long long * [N + 1];

	for (int i = 0; i <= N; i++) 
	{
		dp[i] = new long long[N + 1];
		for (int j = 0; j <= N; j++) 
		{
			dp[i][j] = -1;
		}
	}

	long long answer = 0;

	for (int i = 0; i < N; i++)
	{
		answer = max(answer, cake[i] + IOI(i, i));
	}
	cout << answer << endl;

	return 0;
}