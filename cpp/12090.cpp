#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
	setlocale(LC_ALL, "");

	std::wstring str;
	std::wcin >> str;

	const wchar_t table[20] = L"ぁあいぇえぉけげこさざしじすずせぜそぞ";
	for (int i = 0; i < str.size(); ++i)
	{
		wchar_t coda = (str[i] - 0xAC00) % 28;
		wchar_t onset = ((str[i] - 0xAC00) / 28) / 21;

		if (onset < 20 && onset >= 0)
		{
			std::wcout << table[onset];
		}
		else
		{
			std::wcout << str[i];
		}
	}
	std::wcout << std::endl;
}