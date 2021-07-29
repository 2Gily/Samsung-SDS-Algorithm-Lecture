#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
#define MAX 15

using namespace std;

int N;
int col[15];
int result = 0;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool promising(int i)
{
	for (int j = 0; j < i; j++)
	{
		// ���ο� ���� ������ ���� ���� �࿡ �ְų� �밢���� ���� ���
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}
void N_Queen(int i)
{
	if (i == N)
		result += 1;
	else
	{
		for (int j = 0; j < N; j++)
		{
			col[i] = j;

			if (promising(i)) N_Queen(i + 1);
		}
	}
}

int main()
{
	/*
	1.üũ��(�湮üũ)
	2.�������ΰ�?(��������)
	3.�� �� �ִ� ���� ��ȸ(����� ��)
	4.�� �� �ִ� ��?(���� üũ, ����üũ)
	5.����.(execute)
	6.üũ�ƿ�
	*/
	init();
	cin >> N;

	N_Queen(0);

	cout << result << endl;

	return 0;
}