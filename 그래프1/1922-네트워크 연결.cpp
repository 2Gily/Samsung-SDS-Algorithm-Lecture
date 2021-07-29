#include <iostream>
#include <queue>

using namespace std;

struct Edge 
{
	int src, dst, cost;

	Edge(int a, int b, int c) 
	{
		src = a; dst = b; cost = c;
	}
};

struct compare 
{
	bool operator() (Edge a, Edge b) 
	{
		return a.cost > b.cost;
	}
};

priority_queue<Edge, vector<Edge>, compare> edges;
int* parent;

int FindSet(int a) 
{
	if (parent[a] == a) return a;
	else return parent[a] = FindSet(parent[a]);
}

void UnionSet(int a, int b) 
{
	int rootA = FindSet(a);
	int rootB = FindSet(b);
	parent[rootB] = rootA;
}

int main(int argc, const char * argv[]) 
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int N, M;
	cin >> N >> M;

	parent = new int[N + 1];
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) 
	{
		int src, dst, cost;
		cin >> src >> dst >> cost;

		if (src != dst) edges.push(Edge(src, dst, cost));
	}

	int totalCost = 0, totalCount = 0;

	while (!edges.empty()) 
	{
		Edge now = edges.top(); edges.pop();

		if (totalCount == N - 1) break;

		if (FindSet(now.src) != FindSet(now.dst)) 
		{
			UnionSet(now.src, now.dst);
			totalCost += now.cost;
			totalCount++;
		}
	}

	cout << totalCost << endl;

	return 0;
}