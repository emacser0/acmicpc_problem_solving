#include <cstdio>
int n, nums[1004], dp[1004];
int
main() {
	int max=0,max_sum=0;
	scanf("%d%d", &n,nums);
	max_sum= dp[0] = nums[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", nums+i);
		max = 0;
		for (int j = 0; j <= i; j++) {
			if (nums[i] > nums[j]) {
				max = max > dp[j] ? max : dp[j];
			}
		}
		dp[i] += max + nums[i];
		max_sum = max_sum > dp[i] ? max_sum : dp[i];
	}
	printf("%d\n", max_sum);
}