#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

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
	���� �ִ� ���
	- �ܹ���, ����
	- ������, ������ ����
	- ������ �ִܰ�� (������ ����)
	- ������ �����ϰ� �ִܰŸ��� ���ض�

	1) �ִܰ�θ� ���Ѵ�. ���-���� ����, ��������X
		M(����) -10,000 O(E * logV)
	2) �ִ� ��θ� �����.
		a.���� �� �ִܰ�� ��� ��� - ���ͽ�Ʈ�� �� ��
		b.��Ʈ��ŷ���� ��θ� �ƿ� ������
	3) ���ο� �ִܰ�θ� ���Ѵ�.
		-> ���ͽ�Ʈ��.
	*/
	while (1)
	{
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		int start, end;
		cin >> start >> end;
	}


	return 0;
}