#include <iostream>
#include <algorithm>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void quicksort(int arr[], int left, int right)
{
	int pivot = arr[left];
	int l = left;
	int r = right + 1;

	if (l < r)
	{
		do
		{
			do
				++l;
			while (l <= r && arr[l] < pivot);

			do
				--r;
			while (l <= r && arr[r] > pivot);

			if (l < r)
			{
				swap(arr[l], arr[r]);
			}
		} while (l < r);
		swap(arr[left], arr[r]);

		int pivotPos = r;

		quicksort(arr, left, pivotPos - 1);
		quicksort(arr, pivotPos + 1, right);
	}	
}

int arr[100001];
int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr + N, std::greater<>());

	long long sum = 0;
	for (long long i = 0; i < N; ++i)
	{
		sum += arr[i] >= i ? arr[i] - i : 0;
	}

	std::cout << sum << std::endl;
}