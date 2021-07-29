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

	while (end < N) // A[1]+A[2]+ ··· + A[n]까지 loop문으로 돌리는게 아니라 기존의 값에서 더하고, 빼는 방식!!
	{
		if (sum < M) // sum 이 더 커져야 하는 상황. 즉 end 포인터가 더 오른쪽으로 가야 한다.
		{ 
			end++;
			if (end < N) sum += number[end];
		}
		else if (sum > M) // sum 이 더 작아져야 하는 상황. 즉 start 포인터가 더 오른쪽으로 가야 한다.
		{ 
			sum -= number[start];
			start++;
		}
		else if (sum == M) // sum 이 M 과 같아졌으므로 현재의 star, end 로는 이 다음부터는 [start, end + 1] 도, [start + 1, end] 도 답이 될 수 없다. 두 포인터 다 더 오른쪽으로 한 칸씩 이동시킨다. 
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