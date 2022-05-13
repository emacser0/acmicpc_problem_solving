#include <cstdio>
#include <cstdlib>

int coordinates[10][2] = {
			{1, 3},
	{0, 0}, {1, 0}, {2, 0},
	{0, 1}, {1, 1}, {2, 1},
	{0, 2}, {1 ,2}, {2, 2},	        
};

int getEffort(int hour, int minute)
{
	int v[4] = {
		(hour / 10) % 10,
		hour % 10,
		(minute / 10) % 10,
		minute % 10
	};

	int s = 0;
	for (int i = 0; i < 3; ++i)
	{
		s += abs(coordinates[v[i]][0] - coordinates[v[i + 1]][0]) + abs(coordinates[v[i]][1] - coordinates[v[i + 1]][1]);
	}

	return s;
}

int main()
{
	char str[99];
	fgets(str, 99, stdin);

	int hour = (str[0] - '0') * 10 + str[1] - '0';
	int minute = (str[3] - '0') * 10 + str[4] - '0';

	int rHour = hour;
	int rMinute = minute;

	for (int h = hour; h <= 99; h += 24)
	{
		for (int m = minute; m <= 99; m += 60)
		{
			if (getEffort(rHour, rMinute) > getEffort(h, m))
			{
				rHour = h;
				rMinute = m;
			}
		}
	}

	printf("%.2d:%.2d\n", rHour, rMinute);

}