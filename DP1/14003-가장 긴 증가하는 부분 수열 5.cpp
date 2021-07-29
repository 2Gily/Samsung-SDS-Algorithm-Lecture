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
	이진 탐색을 통한 LIS를 구해야함
	입력값이 너무 많음 100만개

	일반적인 dp 로 구현하면 시간복잡도가 O(n^2) 이기 때문에 시간제한안에 풀 수 없습니다.
	이 문제에서는 이분탐색을 이용하여 풀게 됩니다.
	배열의 시작부터 끝까지 순회하면서
	vector v 를 v[i] : 가능한 길이 i의 증가하는 부분 수열의 마지막 원소 중 최솟값
	을 유지합니다.
	새로운 배열의 원소 A[i]를 순회하면서 v에서 A[i]이상인 위치를 찾아내어 (lower_bound를 이용하여)
	v를 update 해줍니다.
	이러면 시간 O(n logn) 안에 해결할 수 있습니다.
	끝으로 vector pos 은 배열의 각 원소가 v의 어느 위치에 추가되었는지 저장하여,
	가장 긴 증가 부분수열을 추적할 수 있도록 해줍니다.
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