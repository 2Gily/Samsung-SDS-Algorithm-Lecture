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

	int N, M;
	cin >> N >> M;

	vector<int> number(N);
	for (int i = 0; i < N; i++) cin >> number[i];
	
	int start = 0;
	int end = 0;
	int sum = number[0];
	int answer = 0;

	while (end < N) // A[1]+A[2]+ ������ + A[n]���� loop������ �����°� �ƴ϶� ������ ������ ���ϰ�, ���� ���!!
	{
		if (sum < M) // sum �� �� Ŀ���� �ϴ� ��Ȳ. �� end �����Ͱ� �� ���������� ���� �Ѵ�.
		{ 
			end++;
			if (end < N) sum += number[end];
		}
		else if (sum > M) // sum �� �� �۾����� �ϴ� ��Ȳ. �� start �����Ͱ� �� ���������� ���� �Ѵ�.
		{ 
			sum -= number[start];
			start++;
		}
		else if (sum == M) // sum �� M �� ���������Ƿ� ������ star, end �δ� �� �������ʹ� [start, end + 1] ��, [start + 1, end] �� ���� �� �� ����. �� ������ �� �� ���������� �� ĭ�� �̵���Ų��. 
		{ 
			sum -= number[start];
			start++;
			end++;
			if (end < N) sum += number[end];
				
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}