#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M, K; // ������ ����, ���� ������ �Ͼ�� Ƚ��, ������ ���� ���ϴ� Ƚ��
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
//	// ���� ��� ä��� (s-1 ~ 1), leftchild, rightchild
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
//	 // Leaf���� left, right ����
//	int left = S + queryLeft - 1;
//	int right = S + queryRight - 1;
//	long sum = 0;
//	while (left <= right)
//	{
//		// ���� ��尡 Ȧ���̸� ���� ��� �� ����ϰ� ��ĭ ������
//		if (left % 2 == 1)
//		{
//			sum += tree[left++];
//		}
//		// ���� ��尡 ¦���̸� ���� ��� �� ����ϰ� ��ĭ ������
//		if (right % 2 == 0)
//		{
//			sum += tree[right--];
//		}
//		// ����,���� ��� �θ�� �̵�
//		left /= 2;
//		right /= 2;
//	}
//
//	return sum;
//}
//
//void updateBU(int target, long long value)
//{
//	// Leaf���� target�� ã��
//	int node = S + target - 1;
//	// value �ݿ�
//	tree[node] = value;
//	// Root�� ���� �� �� ���� �θ� �� �ݿ�.
//	node /= 2;
//	while (node > 0)
//	{
//		tree[node] = tree[node * 2] + tree[node * 2 + 1];
//	}
//}

long long tree_init(int left, int right, int node)
{
	//���� ����� ���
	if (left != right)
	{
		int mid = (left + right) / 2;

		tree_init(left, mid, node * 2);
		tree_init(mid + 1, right, node * 2 + 1);
		index_tree[node] = index_tree[node * 2] + index_tree[node * 2 + 1];
		return index_tree[node];
	}
	else //��������� ���
	{
		index_tree[node] = num[left];
		return index_tree[node];
	}
}

long long query(int left, int right, int node, int queryLeft, int queryRight)
{
	if (queryRight < left || right < queryLeft) // ������ ���� -> ����� ������ ���� �� return
	{
		return 0;
	}
	else if(queryLeft <= left && right <= queryRight) // �Ǵ� ���� -> ���� ��� �� return
	{
		return index_tree[node];
	}
	else // �ǴܺҰ�, �ڽĿ��� ����, �ڽĿ��� �ö�� ���� return
	{
		int mid = (left + right) / 2;

		return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
	}

	return 0;
}

void update(int left, int right, int node, int target, long long diff)
{
	// ���� ����
	// ���� ���� -> ���� ��忡 diff �ݿ� -> �ڽĿ��� diff 
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
	//while (start < N) // leaf node�� ������ Ʈ���� ��� ����
	//{
	//	start <<= 1;
	//}

	//index_tree.assign(start * 2, 0); // Ʈ�� ������ ���ϱ�

	//for (int i = 0; i < N; i++) // leaf node ä���
	//{
	//	cin >> index_tree[start + i];
	//}
	//for (int i = start - 1; i > 0; i--) // Ʈ���� ���� �� ���ϱ�(leaf node ������ node)
	//{
	//	index_tree[i] = index_tree[i * 2] + index_tree[i * 2 + 1];
	//}
	//initial end


	int start = 1;
	while (start < N) // leaf node�� ������ Ʈ���� ��� ����
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