#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M, K; // 숫자의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수
vector<long long> index_tree;
vector<long long> num;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

//void tree_init(int start)
//{
//	for (int i = 0; i < num.size(); i++)
//	{
//		index_tree[start + i] = num[i];
//	}
//
//	// 내부 노드 채우기 (s-1 ~ 1), leftchild, rightchild
//	for (int i = start - 1; i >= 1; i--)
//	{
//		int left = i * 2;
//		int right = i * 2 + 1;
//		index_tree[i] = index_tree[left] + index_tree[right];
//	}
//}
//
//long long queryBU(int queryLeft, int queryRight)
//{
//	 // Leaf에서 left, right 설정
//	int left = S + queryLeft - 1;
//	int right = S + queryRight - 1;
//	long sum = 0;
//	while (left <= right)
//	{
//		// 좌측 노드가 홀수이면 현재 노드 값 사용하고 한칸 옆으로
//		if (left % 2 == 1)
//		{
//			sum += tree[left++];
//		}
//		// 우측 노드가 짝수이면 현재 노드 값 사용하고 한칸 옆으로
//		if (right % 2 == 0)
//		{
//			sum += tree[right--];
//		}
//		// 좌측,우측 모두 부모로 이동
//		left /= 2;
//		right /= 2;
//	}
//
//	return sum;
//}
//
//void updateBU(int target, long long value)
//{
//	// Leaf에서 target을 찾음
//	int node = S + target - 1;
//	// value 반영
//	tree[node] = value;
//	// Root에 도달 할 때 까지 부모에 값 반영.
//	node /= 2;
//	while (node > 0)
//	{
//		tree[node] = tree[node * 2] + tree[node * 2 + 1];
//	}
//}

long long tree_init(int left, int right, int node)
{
	//내부 노드일 경우
	if (left != right)
	{
		int mid = (left + right) / 2;

		tree_init(left, mid, node * 2);
		tree_init(mid + 1, right, node * 2 + 1);
		index_tree[node] = index_tree[node * 2] + index_tree[node * 2 + 1];
		return index_tree[node];
	}
	else //리프노드일 경우
	{
		index_tree[node] = num[left];
		return index_tree[node];
	}
}

long long query(int left, int right, int node, int queryLeft, int queryRight)
{
	if (queryRight < left || right < queryLeft) // 연관이 없음 -> 결과에 영향이 없는 값 return
	{
		return 0;
	}
	else if(queryLeft <= left && right <= queryRight) // 판단 가능 -> 현재 노드 값 return
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
	// 연관 없음
	// 연관 있음 -> 현재 노드에 diff 반영 -> 자식에게 diff 
	if (target < left || right < target)
	{
		return;
	}
	else
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

void test_print(void)
{
	for (int i = 1; i < index_tree.size(); i++)
	{
		cout << index_tree[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	init();
	cin >> N >> M >> K;

	// initial start
	//int start = 1;
	//while (start < N) // leaf node를 제외한 트리의 노드 개수
	//{
	//	start <<= 1;
	//}

	//index_tree.assign(start * 2, 0); // 트리 사이즈 정하기

	//for (int i = 0; i < N; i++) // leaf node 채우기
	//{
	//	cin >> index_tree[start + i];
	//}
	//for (int i = start - 1; i > 0; i--) // 트리의 구간 합 구하기(leaf node 제외한 node)
	//{
	//	index_tree[i] = index_tree[i * 2] + index_tree[i * 2 + 1];
	//}
	//initial end


	int start = 1;
	while (start < N) // leaf node를 제외한 트리의 노드 개수
	{
		start <<= 1;
	}
	num.assign(N + 1, 0);
	index_tree.assign(start * 2, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	tree_init(1, N, 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long diff = c - index_tree[start + b -1];
			update(1, N, 1, b, diff);
		}
		else if (a == 2)
		{
			cout << query(1, N, 1, b, c) << endl;
		}
	}

	return 0;
}