#include <cstdio>
#include <cstring>

// �Է�
// ���ĺ� �빮�ڷθ� �̷���� ���ڿ� S (1 <= len(S) <= 50)

// ���
// �Ӹ�������� ����� ���� �Ұ����ϸ� "I'm Sorry Hansoo"�� ����ϰ�, �����ϸ� ���������� ���� �ռ��� ���ڿ��� ����Ѵ�.

// alphabetCount: A���� Z���� �� ���ĺ����� ���ڿ����� ��� �����ϴ��� ����.

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

	// oddAlphabetCount: Ȧ���� �����ϴ� ���ĺ��� ����.
	// centerChar: oddAlphabetCount == 1�϶��� �ǹ̰� ����. �Ӹ������ ����� ��ġ�ؾ� �ϴ� ���ĺ��� �ǹ��Ѵ�.

	int oddAlphabetCount = 0;
	char centerChar = '?';

	// h: half, �Ӹ������ ������ �ǹ���.

	char h[54];
	int hLength = 0;

	// p: ����� ����ؾ� �� �Ӹ���� ���ڿ�.

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