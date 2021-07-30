#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 100001
using namespace std;

int N;
int dp[MAX][5][5]; // dp[i][j][k] -> j : �޹�, k : ������, i��° �����϶� �ִ����� ����
vector<int> input;

int score(int from, int to) 
{
	// 0. ���� ��ġ�� ������ 1
	if (from == to) return 1;
	// 1. ��� ��� 2
	if (from == 0) return 2;
	// 3. ũ�ν� �ؼ� ������ 4
	if (abs(from - to) == 2) return 4;
	// 4. ���� ���� ������ 3
	return 3;
}

int DDR(int step, int left, int right)
{
	// 1. ������ ���� �����ϸ� ��
	if (step == N)
		return 0;

	// 2. dp�� ���� �������� return
	if (dp[step][left][right] != 0)
	{
		return dp[step][left][right];
	}

	// 3. ������ ����� �� �� ���� ���� ���� �����ϰ� return
	// �޹� �����̴� ��� vs ������ �����̴� ���
	int leftScore = score(left, input[step]) + DDR(step + 1, input[step], right);
	int rightScore = score(right, input[step]) + DDR(step + 1, left, input[step]);

	return dp[step][left][right] = min(leftScore, rightScore);
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
	/*
	���� �̵��� ��� ǥ���� ���ΰ�?
	�Լ��� ����� ������ ����
	�����丵 ����(if else ���� ���� ���� ����)

	�ٽ� �ѹ� ��������
	1) Ż������(��������) - �ɰ� ������ �ɰ��� return
	2) dp[][] ���� ������ return
	3) ������ ����� �� �� �ּ��� ������ �����ϰ� return
	*/
	while (1)
	{
		int temp;
		cin >> temp;
		if (temp == 0) break;

		input.push_back(temp);
	}

	N = input.size();
	cout << DDR(0, 0, 0) << endl;

	return 0;
}