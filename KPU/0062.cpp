#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> genre_count;

struct Song
{
public:
	std::string genre = "";
	int play_count = 0;
	int number = 0;
};

int compare(Song a, Song b)
{
	if (genre_count[a.genre] != genre_count[b.genre])
	{
		return genre_count[a.genre] < genre_count[b.genre];
	}

	if (a.play_count != b.play_count)
	{
		return a.play_count < b.play_count;
	}

	return a.number < b.number;
}

void sort(std::vector<Song>& arr, std::function<int(Song, Song)> compare, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int pivot = left;
	int i = left;
	int j = right;

	while (i < j)
	{
		while (compare(arr[j], arr[pivot]))
		{
			--j;
		}

		while (i < j && !compare(arr[i], arr[pivot]))
		{
			++i;
		}

		Song temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	Song temp = arr[i];
	arr[i] = arr[pivot];
	arr[pivot] = temp;

	sort(arr, compare, left, i);
	sort(arr, compare, i + 1, right);
}

int main()
{
	int n;

	std::cin >> n;

	std::vector<Song> arr;

	for (int i = 0; i < n; ++i)
	{
		Song song;
		song.number = i;

		std::cin >> song.genre >> song.play_count;
		arr.push_back(song);
		if (genre_count.find(song.genre) == genre_count.end())
		{
			genre_count[song.genre] = 0;
		}

		genre_count[song.genre] += song.play_count;
	}


	sort(arr, compare, 0, n - 1);

	for (auto& item : genre_count)
	{
		genre_count[item.first] = 0;
	}

	for (auto& song : arr)
	{
		if (genre_count[song.genre] >= 2)
		{
			continue;
		}

		std::cout << song.number << std::endl;

		++genre_count[song.genre];
	}
}