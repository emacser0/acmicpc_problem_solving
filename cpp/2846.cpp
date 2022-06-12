// �Է�
// ù°�ٿ� ������ ũ���� N (1 <= N <= 1000) �� �־�����.
// �ι�°�ٿ� N���� ���� ���� Pi (1 <= Pi <= 1000)�� �־�����.


// ���
// ù°�ٿ� ���� ū ���������� ũ�⸦ ����Ѵ�.

#include <cstdio>

int main()
{

	// N: ������ ũ��
	// arr: ������ ���̷� �̷���� ����, ���̰� N�̴�.

	int N;
	int arr[1004];

	scanf("%d", &N);	
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", arr + i);
	}

	// currentHeight: ���� ���������� ����
	// maxHeight: ���������� �ִ� ����

	int currentHeight = 0;
	int maxHeight = 0;

	// ������ ������ �� ����� ���Ǹ� ���� Ʈ��
	arr[N] = arr[N - 1];

	for (int i = 0; i < N; ++i)
	{
		if (arr[i + 1] <= arr[i])
		{
			maxHeight = maxHeight > currentHeight ? maxHeight : currentHeight;
			currentHeight = 0;
		}
		else
		{
			currentHeight += arr[i + 1] - arr[i];
		}
	}

	printf("%d\n", maxHeight);
}