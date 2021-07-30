#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int N;
int *cake;
long long **dp;

// 함수선언부가 있어야함, 식별자 에러 발생.
long long IOI(int , int );
long long JOI(int , int );

int goLeft(int idx)
{
	return (N + idx - 1) % N;
}

int goRight(int idx)
{
	return (idx + 1) % N;
}

long long IOI(int left, int right)
{
	// 1. 가장 끝까지 왔으면
	if (goRight(right) == left)
	{
		return 0;
	}
	// 2. 왼쪽이 더 크면 왼쪽으로, 아니면 오른쪽으로
	if (cake[goLeft(left)] > cake[goRight(right)])
	{
		return JOI(goLeft(left), right);
	}
	return JOI(left, goRight(right));
}

long long JOI(int left, int right)
{
	// 기저 조건
	if (goRight(right) == left) return dp[left][right] = 0;
	// 기저 조건 2
	if (dp[left][right] != -1) return dp[left][right]; 

	//left / right 재귀적으로 뿌린 것 합침.
	long long leftV = cake[goLeft(left)] + IOI(goLeft(left), right);
	long long rightV = cake[goRight(right)] + IOI(left, goRight(right));

	return dp[left][right] = max(leftV, rightV);
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	/*
	[문제 조건]
	- 조각 :  1부터 N 까지 반시계방향으로 번호
	- 0번째는 N 번째, N + 1 번째는 1번째로 간주한다. 원형(Cycle)
	- i 번째 조각의 크기는 A[i]
	1. 먼저, JOI 군이 N 개의 조각 중 원하는 것 하나를 가져간다.
	2. 번갈아가며 남은 조각을 하나씩 가져간다. 단, 인접한 조각 중 하나 이상의 조각이 이미 선택된 경우에만 가져갈 수 있다. 
	가져갈 수 있는 조각이 여러 개 있을 때엔, IOI 양은 그 중 가장 큰 조각을 가져가고, JOI 군은 원하는 조각을 가져갈 수 있다.
	
	정답 = > JOI 가져온 조각들 크기의 최대핪(MAX_SUM)
	*/

	/*
	[내 생각]
	dp[i][j][k] -> 카드 문제와 마찬가지로 두 명의 사람에서 케이크의 조각을 나눠 가지는 문제
	i : 0 : J군, 1 : I 양, j : left, k : right
	완전탐색 -> 분할 정복 -> 조건 : 환형(Cycle) -> moduler 연산자를 이용해서 환형구조 
	기저조건 -> left == right
	*/

	/*
	[필기]
	- 카드 게임과 비슷
	- 2명에서 게임
		1. 분할정복 / 1개 함수에서 falg 나눠서 해도 됨.
		2. 2개 함수 JOI, IOI 나눠서
	- JOI 군의 크기 합을 최대화
	- JOI 먼저 시작

	- 1 ~ N : 환형, 순환형
	  0번째 : N, 1번쨰 : 1(N + 1)

	  int goRight(int idx)
	  {
		return (idx + 1) % N;
	  }
	  int goLeft(int idx)
	  {
		return (N + idx - 1) % N;
	  }
	*/

	init();
	cin >> N;

	cake = new int[N + 1];

	for (int i = 0; i < N; i++) 
	{
		cin >> cake[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> cake[i];
	}

	dp = new long long * [N + 1];

	for (int i = 0; i <= N; i++) 
	{
		dp[i] = new long long[N + 1];
		for (int j = 0; j <= N; j++) 
		{
			dp[i][j] = -1;
		}
	}

	long long answer = 0;

	for (int i = 0; i < N; i++)
	{
		answer = max(answer, cake[i] + IOI(i, i));
	}
	cout << answer << endl;

	return 0;
}