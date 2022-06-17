#include <cstdio>
#include <cstring>

// 입력
// 알파벳 대문자로만 이루어진 문자열 S (1 <= len(S) <= 50)

// 출력
// 팰린드롬으로 만드는 것이 불가능하면 "I'm Sorry Hansoo"를 출력하고, 가능하면 사전순으로 가장 앞서는 문자열을 출력한다.

// alphabetCount: A부터 Z까지 각 알파벳들이 문자열에서 몇번 등장하는지 저장.

int alphabetCount[26];

int main()
{
	char str[54];
	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{ 
		++alphabetCount[str[i] - 'A'];
	}

	// oddAlphabetCount: 홀수번 등장하는 알파벳의 갯수.
	// centerChar: oddAlphabetCount == 1일때만 의미가 있음. 팰린드롬의 가운데에 위치해야 하는 알파벳을 의미한다.

	int oddAlphabetCount = 0;
	char centerChar = '?';

	// h: half, 팰린드롬의 반쪽을 의미함.

	char h[54];
	int hLength = 0;

	// p: 결과로 출력해야 할 팰린드롬 문자열.

	char p[54];	
	int pLength = 0;

	for (int i = 0; i < 26; ++i)
	{
		while (alphabetCount[i] % 2)
		{
			++oddAlphabetCount;
			centerChar = 'A' + i;
			--alphabetCount[i];
		}

		while (alphabetCount[i] >= 2)
		{
			h[hLength] = 'A' + i;
			++hLength;
			alphabetCount[i] -= 2;
		}
	}

	for (int i = 0; i < hLength; ++i)
	{
		p[pLength++] = h[i];
	}

	if (oddAlphabetCount)
	{
		p[pLength++] = centerChar;
	}

	for (int i = 0; i < hLength; ++i)
	{
		p[pLength++] = h[hLength - i - 1];
	}

	p[pLength] = '\0';

	printf("%s\n", oddAlphabetCount > 1 ? "I'm Sorry Hansoo" : p);
}