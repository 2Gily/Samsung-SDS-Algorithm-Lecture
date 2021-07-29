#include <stdio.h>

int max_heap[100001];
int min_heap[100001];
int max_size = 0;
int min_size = 0;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_insert(int n)
{
	int idx = ++max_size;

	while (idx != 1 && n > max_heap[idx / 2])
	{
		max_heap[idx] = max_heap[idx / 2];
		idx /= 2;
	}
	max_heap[idx] = n;
}

void min_insert(int n)
{
	int idx = ++min_size;

	while (idx != 1 && n < min_heap[idx / 2]) 
	{
		min_heap[idx] = min_heap[idx / 2];
		idx /= 2;
	}
	min_heap[idx] = n;
}

int max_del() 
{
	if (max_size == 0)
	{
		return 0;
	}

	int value = max_heap[1];
	max_heap[1] = max_heap[max_size--];
	int parent = 1;
	int child;

	while (1) 
	{
		child = parent * 2;
		if (child + 1 <= max_size && max_heap[child] < max_heap[child + 1])
		{
			child++;
		}
		if (child > max_size || max_heap[child] < max_heap[parent])
		{
			break;
		}
		swap(&max_heap[parent], &max_heap[child]);
		parent = child;
	}
	return value;
}

int min_del()
{
	if (min_size == 0) 
	{
		return 0;
	}
	int value = min_heap[1];
	min_heap[1] = min_heap[min_size--];
	int parent = 1;
	int child;
	while (1) 
	{
		child = parent * 2;
		if (child + 1 <= min_size && min_heap[child] > min_heap[child + 1])
		{
			child++;
		}
		if (child > min_size || min_heap[child] > min_heap[parent]) 
		{
			break;
		}
		swap(&min_heap[parent], &min_heap[child]);
		parent = child;
	}
	return value;
}

int main() 
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		int d;
		scanf("%d", &d);

		if (i == 0) 
		{
			max_insert(d);
		}
		else if (i == 1) 
		{
			min_insert(d);
			if (max_heap[1] > min_heap[1]) swap(&max_heap[1], &min_heap[1]);
		}
		else 
		{
			if (d <= max_heap[1])
			{
				max_insert(d);
			}
			else if (d >= min_heap[1])
			{
				min_insert(d);
			}
			else 
			{
				if (max_size == min_size)
				{
					max_insert(d);
				}
				else if (max_size > min_size) 
				{
					min_insert(d);
				}
			}

			if (max_size >= min_size + 2) 
			{
				while (max_size >= min_size + 2)
				{
					min_insert(max_del());
				}
			}
			else if (min_size >= max_size + 1)
			{
				while (min_size >= max_size + 1) 
				{
					max_insert(min_del());
				}
			}
		}

		printf("%d\n", max_heap[1]);
	}

	return 0;
}