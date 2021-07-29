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
	거의 최단 경로
	- 단방향, 간선
	- 시작점, 도착점 고정
	- 굵은선 최단경로 (여러개 가능)
	- 굵은선 제외하고 최단거리를 구해라

	1) 최단경로를 구한다. 출발-도착 고정, 음수간선X
		M(간선) -10,000 O(E * logV)
	2) 최단 경로를 지운다.
		a.여러 개 최단경로 모두 기록 - 다익스트라 할 때
		b.백트래킹으로 경로를 아예 지우자
	3) 새로운 최단경로를 구한다.
		-> 다익스트라.
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