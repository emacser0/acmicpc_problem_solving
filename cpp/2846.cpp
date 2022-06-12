// 입력
// 첫째줄에 수열의 크기인 N (1 <= N <= 1000) 이 주어진다.
// 두번째줄에 N개의 양의 정수 Pi (1 <= Pi <= 1000)가 주어진다.


// 출력
// 첫째줄에 가장 큰 오르막길의 크기를 출력한다.

#include <cstdio>

int main()
{

	// N: 수열의 크기
	// arr: 측정한 높이로 이루어진 수열, 길이가 N이다.

	int N;
	int arr[1004];

	scanf("%d", &N);	
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", arr + i);
	}

	// currentHeight: 현재 오르막길의 높이
	// maxHeight: 오르막길의 최대 높이

	int currentHeight = 0;
	int maxHeight = 0;

	// 수열의 마지막 값 계산의 편의를 위한 트릭
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