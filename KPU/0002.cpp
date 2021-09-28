#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;

	long long a_sum = 0;
	long long b_sum = 0;
	long long max_lead = 0;
	for (auto i = 0; i < N; ++i)
	{
		int a, b;
		std::cin >> a >> b;

		a_sum += a;
		b_sum += b;

		long long lead = a_sum - b_sum;

		if ((max_lead > 0 ? max_lead : -max_lead) < (lead > 0 ? lead : -lead))
		{
			max_lead = lead;
		}
	}

	if (max_lead > 0)
	{
		std::cout << 1 << " " << max_lead << std::endl;
	}
	else
	{
		std::cout << 2 << " " << -max_lead << std::endl;
	}
}