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
	/*
	LIS
	���� Ž���� ���� LIS�� ���ؾ���
	�Է°��� �ʹ� ���� 100����

	�Ϲ����� dp �� �����ϸ� �ð����⵵�� O(n^2) �̱� ������ �ð����Ѿȿ� Ǯ �� �����ϴ�.
	�� ���������� �̺�Ž���� �̿��Ͽ� Ǯ�� �˴ϴ�.
	�迭�� ���ۺ��� ������ ��ȸ�ϸ鼭
	vector v �� v[i] : ������ ���� i�� �����ϴ� �κ� ������ ������ ���� �� �ּڰ�
	�� �����մϴ�.
	���ο� �迭�� ���� A[i]�� ��ȸ�ϸ鼭 v���� A[i]�̻��� ��ġ�� ã�Ƴ��� (lower_bound�� �̿��Ͽ�)
	v�� update ���ݴϴ�.
	�̷��� �ð� O(n logn) �ȿ� �ذ��� �� �ֽ��ϴ�.
	������ vector pos �� �迭�� �� ���Ұ� v�� ��� ��ġ�� �߰��Ǿ����� �����Ͽ�,
	���� �� ���� �κм����� ������ �� �ֵ��� ���ݴϴ�.
	*/

	init();
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) cin >> A[i];

	vector<int> v;
	v.push_back(A[0]);

	for (int i = 1; i < n; i++) 
	{
		auto it = lower_bound(v.begin(), v.end(), A[i]);
		pos[i] = (it - v.begin());
		if (it == v.end()) v.push_back(A[i]);
		else *it = A[i];
	}

	int sz = v.size();
	cout << sz << '\n';
	vector<int> ans(sz);
	int cnt = sz - 1;

	for (int i = n - 1; i >= 0; i--) 
	{
		if (pos[i] == cnt) 
		{
			ans[cnt--] = A[i];
		}
	}
	for (int e : ans) cout << e << ' ';

	return 0;
}