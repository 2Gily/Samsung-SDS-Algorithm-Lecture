#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, Q;
vector<long long> index_tree;
vector<long long> num;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void tree_init(int start)
{
	for (int i = 0; i < num.size() ; i++)
	{
		index_tree[start + i] = num[i];
	}

	// 내부 노드 채우기 (s-1 ~ 1), leftchild, rightchild
	for (int i = start - 1; i >= 1; i--)
	{
		int left = i * 2;
		int right = i * 2 + 1;
		index_tree[i] = index_tree[left] + index_tree[right];
	}
}

long long query(int left, int right, int node, int queryLeft, int queryRight)
{
	if (queryRight < left || right < queryLeft) // 연관이 없음 -> 결과에 영향이 없는 값 return
	{
		return 0;
	}
	else if (queryLeft <= left && right <= queryRight) // 판단 가능 -> 현재 노드 값 return
	{
		return index_tree[node];
	}
	else // 판단불가, 자식에게 위임, 자식에서 올라온 합을 return
	{
		int mid = (left + right) / 2;

		return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
	}

	return 0;
}

void update(int left, int right, int node, int target, long long diff)
{
	if (target < left || right < target) // 연관 없음
	{
		return;
	}
	else if (left <= target && target <= right) // 연관 있음 -> 현재 노드에 diff 반영 -> 자식에게 diff 
	{
		index_tree[node] += diff;

		if (left != right)
		{
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}

int main(void)
{
	init();
	cin >> N >> Q;

	int start = 1;
	while (start < N) // leaf node를 제외한 트리의 노드 개수
	{
		start <<= 1;
	}
	num.assign(N + 1, 0);
	index_tree.assign(start * 2, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	tree_init(start);

	for (int i = 0; i < Q; i++)
	{
		int x, y, a;
		long long b, diff;
		cin >> x >> y >> a >> b;

		diff = b - index_tree[start + a - 1];

		if (x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}

		cout << query(1, start, 1, x, y) << endl;
		update(1, start, 1, a, diff);
	}

	return 0;
}