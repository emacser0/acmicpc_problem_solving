// �Է�
// ù°�ٿ� N, T, P �� �־�����.
// N: �ι�° �ٿ� �־����� ������ ���� (0 <= N <= P <= 50)
// T: �¼��� ���ο� ���� (0 <= T <= 2,000,000,000)
// P: ��ŷ ����Ʈ�� �ö� �� �ִ� ������ ���� (10 <= P <= 50)

// �ι�° �ٿ� ���� ��ŷ ����Ʈ�� �ִ� ������ ������������� �־�����.
// ������ ������ T�� ���������� 0���� ũ�ų� ���� 2,000,000,000���� �۰ų� ����.


#include <cstdio>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;	
}

int main()
{
	int N, T, P;
	scanf("%d %d %d", &N, &T, &P);

	int arr[99];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", arr + i);

		// Insertion Sort

		for (int j = i; j > 0; --j)
		{
			if (arr[j] >= arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}

	// frontRank: ������ �߿� ���� �տ� �ִ� ������ ������ ����̴�.
	// backRank: ������ �߿� ���� �ڿ� �ִ� ������ ������ ����̴�.

	int frontRank = N;
	arr[N] = T;

	while(frontRank > 0)
	{
		if (arr[frontRank] >= arr[frontRank - 1])
		{
			swap(arr[frontRank], arr[frontRank - 1]);
			--frontRank;
		}
		else
		{
			break;
		}
	}	

	int backRank = frontRank;
	while (backRank < N)
	{
		if (arr[backRank] != arr[backRank + 1])
		{
			break;
		}

		++backRank;
	}
	
	printf("%d\n", backRank + 1 <= P ? frontRank + 1 : -1);
}