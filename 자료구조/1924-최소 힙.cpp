#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int heap[MAX], n;
int idx = 0;

void POP()
{
	if (heap[1] == 0)
	{
		cout << "0" << '\n';
		return;
	}
	else
	{
		cout << heap[1] << '\n';
		heap[1] = heap[idx];
		heap[idx--] = 0;
		int base = 1;

		while ((base * 2 + 1 <= idx) && (heap[base] > heap[base * 2] || heap[base] > heap[base * 2 + 1]))
		{
			if (heap[base * 2] <= heap[base * 2 + 1])
			{
				int temp = heap[base * 2];
				heap[base * 2] = heap[base];
				heap[base] = temp;
				base = base * 2;
			}
			else
			{
				int temp = heap[base * 2 + 1];
				heap[base * 2 + 1] = heap[base];
				heap[base] = temp;
				base = base * 2 + 1;
			}
		}

		if (base * 2 <= idx)
		{
			if (heap[base] > heap[base * 2])
			{
				int temp = heap[base * 2];
				heap[base * 2] = heap[base];
				heap[base] = temp;
			}
		}
	}
}

void PUSH(int x)
{
	heap[++idx] = x;
	int base = idx;

	while (base / 2 >= 1 && heap[base] < heap[base / 2])
	{
		int temp = heap[base / 2];
		heap[base / 2] = heap[base];
		heap[base] = temp;
		base = base / 2;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		int temp;
		cin >> temp;

		if (temp == 0) POP();
		else PUSH(temp);
	}
}