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
		// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
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
	1.체크인(방문체크)
	2.목적지인가?(기저조건)
	3.갈 수 있는 곳을 순회(경우의 수)
	4.갈 수 있는 가?(범위 체크, 조건체크)
	5.간다.(execute)
	6.체크아웃
	*/
	init();
	cin >> N;

	N_Queen(0);

	cout << result << endl;

	return 0;
}