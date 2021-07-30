#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 100001
using namespace std;

int N;
int dp[MAX][5][5]; // dp[i][j][k] -> j : 왼발, k : 오른발, i번째 스탭일때 최댓값으로 정의
vector<int> input;

int score(int from, int to) 
{
	// 0. 지금 위치를 누르면 1
	if (from == to) return 1;
	// 1. 가운데 출발 2
	if (from == 0) return 2;
	// 3. 크로스 해서 밟으면 4
	if (abs(from - to) == 2) return 4;
	// 4. 인접 스텝 밟으면 3
	return 3;
}

int DDR(int step, int left, int right)
{
	// 1. 마지막 스텝 도달하면 끝
	if (step == N)
		return 0;

	// 2. dp에 값이 차있으면 return
	if (dp[step][left][right] != 0)
	{
		return dp[step][left][right];
	}

	// 3. 가능한 경우의 수 중 가장 적은 경우로 갱신하고 return
	// 왼발 욺직이는 경우 vs 오른발 움직이는 경우
	int leftScore = score(left, input[step]) + DDR(step + 1, input[step], right);
	int rightScore = score(right, input[step]) + DDR(step + 1, left, input[step]);

	return dp[step][left][right] = min(leftScore, rightScore);
}

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
	발의 이동을 어떻게 표현할 것인가?
	함수로 기능을 나누는 연습
	리팩토링 연습(if else 문이 많은 문제 정리)

	다시 한번 분할정복
	1) 탈출조건(기저조건) - 쪼갤 때까지 쪼개면 return
	2) dp[][] 값이 있으면 return
	3) 가능한 경우의 수 중 최선의 값으로 갱신하고 return
	*/
	while (1)
	{
		int temp;
		cin >> temp;
		if (temp == 0) break;

		input.push_back(temp);
	}

	N = input.size();
	cout << DDR(0, 0, 0) << endl;

	return 0;
}