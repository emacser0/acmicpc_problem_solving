#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <cassert>

// �Է�
// �� �ٿ� ���ڿ��� �־���.
// ���ڿ��� ������ �Ʒ��� ����.
// 
// [NumberString]([Base]) + [NumberString]([Notation]) = ([ResultBase])
// NumberString = string
// Base = 2 | 8 | 16

// ���
// �Է¿� ���� Result Base�� �Բ� ����� ������� �����.
// [NumberString]([ResultBase])

// 2048Bits = 256Bytes
// BigInt�� ũ�� = 256Byte
// ������ �������� ���̰� ���Ѵ�� �ƴ�.

#define BIGINT_BITS_LIMIT 2048

struct BigInt
{
private:
	static std::regex re;
	static std::regex reBase2;
	static std::regex reBase8;
	static std::regex reBase16;

public:
	BigInt();
	BigInt(int n);
	BigInt(const std::string& str);
	BigInt(const BigInt& bn);

	~BigInt() { }

	BigInt operator+(const BigInt& other) const;
	BigInt& operator+=(const BigInt& other);
	BigInt operator-(const BigInt& other) const;
	BigInt& operator-=(const BigInt& other);
	BigInt operator*(BigInt& other) const;
	BigInt& operator*=(BigInt& other);
	BigInt operator<<(int num) const;
	BigInt operator>>(int num) const;
	BigInt& operator<<=(int num);
	BigInt& operator>>=(int num);
	BigInt operator|(const BigInt& other) const;
	BigInt operator&(const BigInt& other) const;
	BigInt operator^(const BigInt& other) const;
	BigInt operator~() const;
	BigInt& operator|=(const BigInt& other);
	BigInt& operator&=(const BigInt& other);
	BigInt& operator^=(const BigInt& other);

	// getTwosComplement: �ڽ��� 2�� ������ ���ϴ� �Լ�
	// flip: �ڽ��� 2�� ������ ������ �Լ�
	// getLength: ���� �ڸ����� ���� 1������ ���̸� ���ϴ� �Լ�
	// sign: ��ȣ�� ���ϴ� �Լ�. 1 or -1

	BigInt getTwosComplement() const;
	void flip();
	int getLength() const;
	int sign() const;

	std::string toString(int base) const;
	
	bool bits[BIGINT_BITS_LIMIT];
};

// std::regex::optimize �÷��׸� ����ϸ�, ���Խ� �������� ���� �ɸ����� ���� ������ ������. 
// �ѹ��� �������ϸ� �ǹǷ� ���Խ��� ������ ����� ��쿡 �̵���.

// Operand �Է� ���˿� �´��� Ȯ���ϴ� ���Խ�
std::regex BigInt::re = std::regex("(-?[0-9A-F]+)\\(([0-9]+)\\)", std::regex::optimize);
// 2���� �������� Ȯ���ϴ� ���Խ�
std::regex BigInt::reBase2 = std::regex("[0-1]+", std::regex::optimize);
// 8���� �������� Ȯ���ϴ� ���Խ�
std::regex BigInt::reBase8 = std::regex("[0-7]+", std::regex::optimize);
// 16���� �������� Ȯ���ϴ� ���Խ�
std::regex BigInt::reBase16 = std::regex("[0-9A-F]+", std::regex::optimize);

int main()
{
	char buf[1024];
	std::cin.getline(buf, 1024);

	std::stringstream tokenStream(buf);
	std::string token;

	std::vector<std::string> tokens;
	while (tokenStream >> token)
	{
		tokens.push_back(token);
	}

	assert(tokens.size() == 5);
	assert(tokens[3] == "=");

	BigInt lOperand(tokens[0]);
	BigInt rOperand(tokens[2]);

	std::smatch resultBaseMatch;
	assert(std::regex_match(tokens[4], resultBaseMatch, (std::regex("\\(([0-9]+)\\)"))));
	assert(resultBaseMatch.size() == 2);

	int resultBase = std::stoi(resultBaseMatch[1]);

	assert(resultBase == 2 || resultBase == 8 || resultBase == 16);

	BigInt result;
	if (tokens[1] == "+")
	{
		result = lOperand + rOperand;
	}
	else if (tokens[1] == "-")
	{
		result = lOperand - rOperand;
	}
	else if (tokens[1] == "*")
	{
		result = lOperand * rOperand;
	}

	std::cout << result.toString(resultBase) << "(" << resultBase << ")" << std::endl;

	return 0;
}

BigInt::BigInt()
{
	memset(bits, 0, sizeof(bits));
}

// ���������� ���ö�
BigInt::BigInt(int n) : BigInt()
{
	int isNegative = n < 0;
	if (isNegative)
	{
		n = -n;
	}

	int index = 0;
	while (n)
	{
		bits[index++] = n & 0x1;
		n >>= 1;
	}

	if (isNegative)
	{
		flip();
	}
}


// Operand �������� ���� ��
// example: 1C27BA(16)
BigInt::BigInt(const std::string& str) : BigInt()
{
	std::smatch match;

	assert(std::regex_match(str, match, re));
	assert(match.size() == 3);

	std::string number = match[1];
	int base = std::stoi(match[2]);

	assert(base == 2 || base == 8 || base == 16);

	bool isNegative = number[0] == '-';
	if (isNegative)
	{
		number.erase(number.begin());
	}

	// �Է��� 2���� �����϶�
	if (base == 2)
	{
		assert(std::regex_match(number, reBase2));

		for (int i = 0; i < number.size(); ++i)
		{
			bits[i] = number[number.size() - i - 1] - '0';
		}
	}
	// �Է��� 8���� �����϶�
	else if (base == 8)
	{
		assert(std::regex_match(number, reBase8));

		for (int i = 0; i < number.size(); ++i)
		{
			// unit: 8������ �� �ڸ����� �ǹ���.

			int unit = number[number.size() - i - 1] - '0';

			for (int j = 0; j < 3; ++j)
			{
				bits[i * 3 + j] = unit & (0x1 << j);
			}
		}
	}
	// �Է��� 16���� �����϶�
	else if (base == 16)
	{
		assert(std::regex_match(number, reBase16));

		for (int i = 0; i < number.size(); ++i)
		{
			// unit: 16������ �� �ڸ����� �ǹ���.

			int unit = number[number.size() - i - 1];
			if (unit >= 'A')
			{
				unit = unit - 'A' + 10;
			}
			else
			{
				unit -= '0';
			}

			for (int j = 0; j < 4; ++j)
			{
				bits[i * 4 + j] = unit & (0x1 << j);
			}
		}
	}

	if (isNegative)
	{
		flip();
	}
}

BigInt::BigInt(const BigInt& bn) { memcpy(bits, bn.bits, sizeof(bits)); }

BigInt BigInt::operator+(const BigInt& other) const
{
	BigInt result;

	bool carry = 0;
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		bool a = bits[i];
		bool b = other.bits[i];
		bool c = carry;

		// ���� ��Ʈ�� a, b, c ������ ��Ʈ �� 1�� ���� Ȧ�����϶��� 1��.
		result.bits[i] = a ^ b ^ c;
		// carry�� a, b, c ������ ��Ʈ �� �ΰ� �̻� Ȱ��ȭ�Ǿ� ������ 1��.			
		carry = (a & b) | (b & c) | (c & a);
		// carry = ~(a ^ b ^ c) & ~(~a & ~b & ~c) �ε� ���� ����.
	}

	return result;
}

BigInt& BigInt::operator+=(const BigInt& other)
{
	memcpy(bits, (*this + other).bits, sizeof(bits));

	return *this;
}

// 2�� ������ ���� �� ����.
BigInt BigInt::operator-(const BigInt& other) const
{
	BigInt otherNegative(other);
	otherNegative.flip();

	return *this + otherNegative;
}

BigInt& BigInt::operator-=(const BigInt& other)
{
	memcpy(bits, (*this - other).bits, sizeof(bits));

	return *this;
}

// ��Ʈ ����� �������� ���� ����
BigInt BigInt::operator*(BigInt& other) const
{
	int length = getLength();
	int otherLength = other.getLength();

	BigInt result;

	//���ڸ���
	for (int i = 0; i < length; ++i)
	{
		BigInt current(other);
		current <<= i;

		if (bits[i])
		{
			result += current;
		}
	}

	return result;
}

BigInt& BigInt::operator*=(BigInt& other)
{
	memcpy(bits, (*this * other).bits, sizeof(bits));

	return *this;
}

// ���� ���� �ڸ��� index=0 �̹Ƿ� �ǵ��ϴ� ����Ʈ ����� �ݴ�� ó���ؾ���.
BigInt BigInt::operator<<(int num) const
{
	BigInt result;

	for (int i = 0; i < BIGINT_BITS_LIMIT - num; ++i)
	{
		result.bits[i + num] = bits[i];
	}

	return result;
}

BigInt BigInt::operator>>(int num) const
{
	BigInt result;

	bool signbit = bits[BIGINT_BITS_LIMIT - 1];
	for (int i = num; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i - num] = bits[i];
	}

	for (int i = BIGINT_BITS_LIMIT - num - 1; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i] = signbit;
	}

	return result;
}

BigInt& BigInt::operator<<=(int num)
{
	for (int i = BIGINT_BITS_LIMIT - num - 1; i >= 0; --i)
	{
		bits[i + num] = bits[i];
		bits[i] = 0;
	}

	return *this;
}

BigInt& BigInt::operator>>=(int num)
{
	bool signbit = bits[BIGINT_BITS_LIMIT - 1];
	for (int i = num; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i - num] = bits[i];
	}

	for (int i = BIGINT_BITS_LIMIT - num - 1; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i] = signbit;
	}

	return *this;
}

BigInt BigInt::operator|(const BigInt& other) const
{
	BigInt result;

	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i] = bits[i] || other.bits[i];
	}

	return result;
}

BigInt BigInt::operator&(const BigInt& other) const
{
	BigInt result;

	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i] = bits[i] && other.bits[i];
	}

	return result;
}

BigInt BigInt::operator^(const BigInt& other) const
{
	BigInt result;

	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i] = bits[i] ^ other.bits[i];
	}

	return result;
}

BigInt BigInt::operator~() const
{
	BigInt result;

	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		result.bits[i] = !bits[i];
	}

	return result;
}

BigInt& BigInt::operator|=(const BigInt& other)
{
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i] = bits[i] || other.bits[i];
	}

	return *this;
}

BigInt& BigInt::operator&=(const BigInt& other)
{
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i] = bits[i] && other.bits[i];
	}

	return *this;
}

BigInt& BigInt::operator^=(const BigInt& other)
{
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i] = bits[i] ^ other.bits[i];
	}

	return *this;
}

// �ڽ��� 2�� ������ ���ϴ� �Լ�

BigInt BigInt::getTwosComplement() const
{
	BigInt complement;

	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		complement.bits[i] = !bits[i];
	}

	return complement + BigInt(1);
}

// �ڽ��� 2�� ������ ������ �Լ�

inline void BigInt::flip()
{
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		bits[i] = !bits[i];
	}

	bool carry = 1;
	for (int i = 0; i < BIGINT_BITS_LIMIT; ++i)
	{
		if (carry == 0)
		{
			break;
		}

		bool a = bits[i];
		bool b = carry;

		bits[i] = a ^ b;
		carry = a && b;
	}
}

inline int BigInt::getLength() const
{
	for (int i = BIGINT_BITS_LIMIT - 1; i >= 0; --i)
	{
		if (bits[i])
		{
			return i + 1;
		}
	}

	return 0;
}

inline int BigInt::sign() const
{
	return bits[BIGINT_BITS_LIMIT - 1] ? -1 : 1;
}

inline std::string BigInt::toString(int base) const
{
	assert(base == 2 || base == 8 || base == 16);

	BigInt tmp(*this);

	std::string result = "";

	bool isNegative = tmp.bits[BIGINT_BITS_LIMIT - 1];
	if (isNegative)
	{
		tmp.flip();
	}

	int length = tmp.getLength();

	if (base == 2)
	{
		for (int i = 0; i < length; ++i)
		{
			result.push_back(tmp.bits[i] + '0');
		}
	}
	else if (base == 8)
	{
		for (int i = 0; i < length; i += 3)
		{
			char r = 0;
			for (int j = 0; j < 3; ++j)
			{
				if (i + j >= length)
				{
					break;
				}

				r |= tmp.bits[i + j] << j;
			}

			result.push_back(r + '0');
		}
	}
	else if (base == 16)
	{
		for (int i = 0; i < length; i += 4)
		{
			char r = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (i + j >= length)
				{
					break;
				}

				r |= tmp.bits[i + j] << j;
			}

			if (r >= 10)
			{
				result.push_back(r - 10 + 'A');
			}
			else
			{
				result.push_back(r + '0');
			}
		}
	}

	if (result.size() == 0)
	{
		return "0";
	}

	if (isNegative)
	{
		result.push_back('-');
	}

	// ������ ���Ǹ� ���� ���� ���� �ڸ��� ���� ���� ����� ���� ������.
	std::reverse(result.begin(), result.end());

	return result;
}
