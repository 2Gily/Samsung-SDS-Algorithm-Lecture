#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

const int MAX = 1000000 + 1;

bool number[MAX];
vector<int> primeNumbers;

void eratos(int K) // �����佺�׳׽��� ü(�Ҽ� �ƴ� ���� �Ұ��ϴ� ���)
{
	number[0] = number[1] = true;
	// 2~N���� ���� �� N�� �����ٱ��� ���ϴ� ��� N = 100, i*i = 100, i = 10
	// for(int i =2 ; i*i <= N ; i++)
	// {
	//		for(int j = i*i ; j <= N ; j += i)
	// }
	for (int i = 2; i*i < K; i++) 
	{
		if (number[i]) continue;
		cout << i << " prime" << endl;

		for (int j = i*i; j < K; j += i)
		{
			number[j] = true;
		}
	}

	for (int i = 2; i < K; i++)
	{
		if (number[i] == false)
		{
			primeNumbers.push_back(i);
		}
	}
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
	string p;
	int K;
	cin >> p >> K;

	eratos(K);
	// �������� ������ ������� b / a = reuslt�� �� ��, ���ڸ����� %(������ ����)�� �ϰ� �������� x10�� �ϸ鼭 �������� ���
	for (int primeNumber : primeNumbers)
	{
		int div = 0, temp = 1;

		for (int i = p.length() - 1; i >= 0; i--)
		{
			div = (div + (p[i] - '0') * temp) % primeNumber;

			temp *= 10;
			temp %= primeNumber;
		}

		if (div == 0)
		{
			cout << "BAD " << primeNumber << "\n";

			return 0;
		}
	}

	cout << "GOOD\n";

	return 0;
}