#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>

template <typename T>
T Max(T a, T b) { return a > b ? a : b; }

template <typename T>
void Swap(T &a, T &b) { T t = a; a = b; b = t; }

template <typename T>
int compare(T a, T b)
{
  if(a > b) return 1;
  else if(a < b) return -1;
  else return 0;
}

class BigInt
{
public:
  BigInt()
  {
    numvec.push_back(0);
    sign = false;
  }
  BigInt(int n)
  {
    sign = n < 0;
    while(n)
    {
      numvec.push_back(n % 10);
      n /= 10;
    }
  }
  BigInt(long long int n)
  {
    sign = n < 0;
    while(n)
    {
      numvec.push_back(n % 10);
      n /= 10;
    }
  }
  BigInt(const char *str)
  {
    sign = false;
    int len = strlen(str);
    for(int i = 0; i < len; ++i)
      numvec.push_back(str[i]);
    if(numvec[0] =='-')
    {
      for(int i = 1; i < Length(); ++i)
        numvec[i - 1] = numvec[i], numvec[i] = 0;
      sign = true;
      numvec.pop_back();
    }
    for(int i = 0; i < Length(); ++i) numvec[i] -= '0';
    for(int i = 0, j = Length() - 1; i < j; Swap(numvec[i++], numvec[j--]));
  }
  int At_lvalue(int index) const
  {
    if(index < Length())
      return numvec.at(index);
    else
      return 0;
  }
  // int& At(int index) const
  // {
  //   return numvec.at(index);
  // }
  BigInt(const BigInt &n)
  {
    *this = n;
  }
  size_t Length() const
  {
    return numvec.size();
  }
  int Compare(const BigInt &n) const
  {
    if(!sign && n.sign) return 1;
    if(sign && !n.sign) return -1;
    int mode = sign ? -1 : 1;
    if(Length() > n.Length()) return mode;
    if(Length() < n.Length()) return -mode;
    for(int i = Length() - 1; i >= 0; --i)
      if(numvec.at(i) > n[i])
        return mode;
      else if(numvec.at(i) < n[i])
        return -mode;
    return 0;
  }
  int& operator[](const size_t index)
  {
    return numvec.at(index);
  }
  int operator[](const size_t index) const
  {
    return numvec.at(index);
  }
  BigInt operator+(const BigInt &n) const
  {
    int maxlen = Max(Length(), n.Length()) + 1;
    BigInt r;
    r.numvec = std::vector<int>(maxlen, 0);
    if(sign == n.sign)
    {
      if(Length() == n.Length()) maxlen += 1;
      r.sign = sign;
      for(int i = 0; i < maxlen - 1; ++i)
      {
        r[i] += At_lvalue(i) + n.At_lvalue(i);
        if(r[i] > 9)
          r[i] -= 10, r[i + 1] += 1;
      }
    }
    else
    {
      int mode = sign ? -1 : 1;
      for(int i = 0; i < maxlen; ++i)
        r[i] = mode * (At_lvalue(i) - n.At_lvalue(i));
      for(int i = maxlen - 1; i >= 0; --i)
      {
        if(r[i] != 0)
        {
          r.sign = r[i] < 0;
          break;
        }
      }
      mode = r.sign ? -1 : 1;
      for(int i = 0; i < maxlen - 1; r[i] = mode * r[i], ++i)
      {
        if(-compare(r[i], 0) == mode)
          r[i] += mode * 10, r[i + 1] -= mode;
      }
    }
    while(r.numvec.back() == 0 && r.Length() > 1)
      r.numvec.pop_back();
    if(r.Length() == 1 && r[0] == 0) r.sign = 0;
    return r;
  }
  BigInt operator+(int n) const
  {
    BigInt bn(n);
    return *this + bn;
  }
  BigInt operator+(long long int n) const
  {
    BigInt bn(n);
    return *this + bn;
  }
  BigInt& operator+=(const BigInt &n)
  {
    *this = *this + n;
    return *this;
  }
  BigInt& operator+=(long long int n)
  {
    BigInt bn(n);
    return *this += bn;
  }
  BigInt& operator++()
  {
    return *this += 1;
  }
  BigInt& operator-()
  {
    sign = !sign;
    return *this;
  }
  BigInt operator-(const BigInt &n) const
  {
    BigInt r, cn(n);
    cn.sign = !cn.sign;
    return *this + cn;
  }
  BigInt operator-(int n) const
  {
    BigInt bn(n);
    return *this - bn;
  }
  BigInt operator-(long long int n) const
  {
    BigInt bn(n);
    return *this - bn;
  }
  BigInt& operator-=(const BigInt &n)
  {
    BigInt cn(n);
    cn.sign = !cn.sign;
    return *this += cn;
  }
  BigInt& operator-=(int n)
  {
    BigInt bn(n);
    return *this -= bn;
  }
  BigInt& operator-=(long long int n)
  {
    BigInt bn(n);
    return *this -= bn;
  }
  BigInt& operator--()
  {
    return *this -= 1;
  }
  BigInt operator*(const BigInt &n) const
  {
    BigInt r;
    r.numvec = std::vector<int>(Length() + n.Length() + 1, 0);
    if(sign == n.sign) r.sign = 0;
    else r.sign = 1;
    for(int i = 0; i < Length(); ++i)
      for(int j = 0; j < n.Length(); ++j)
        r[i + j] += numvec[i] * n[j];
    for(int i = 0; i < r.Length(); ++i)
      if(r[i] > 9)
        r[i + 1] += r[i] / 10, r[i] = r[i] % 10;
    while(r.numvec.back() == 0 && r.Length() > 1)
      r.numvec.pop_back();
    return r;
  }
  BigInt operator*(int n)
  {
    BigInt bn(n);
    return *this * bn;
  }
  BigInt operator*(long long int n)
  {
    BigInt bn(n);
    return *this * bn;
  }
  BigInt& operator*=(const BigInt &n)
  {
    *this = *this * n;
    return *this;
  }
  BigInt& operator*=(int n)
  {
    BigInt bn(n);
    *this = *this * bn;
    return *this;
  }
  BigInt& operator*=(long long int n)
  {
    BigInt bn(n);
    *this = *this * bn;
    return *this;
  }
  BigInt operator/(const BigInt &n)
  {
    BigInt mod(*this);
    BigInt cnt(0);
    while(mod > n)
    {
      mod -= n;
      ++cnt;
    }
    return cnt;
  }
  BigInt operator/(int n)
  {
    BigInt bn(n);
    return *this / bn;
  }
  BigInt operator/(long long int n)
  {
    BigInt bn(n);
    return *this / bn;
  }
  BigInt& operator/=(const BigInt &n)
  {
    *this = *this / n;
    return *this;
  }
  BigInt& operator/=(int n)
  {
    BigInt bn(n);
    *this = *this / n;
    return *this;
  }
  BigInt& operator/=(long long int n)
  {
    BigInt bn(n);
    *this = *this / n;
    return *this;
  }
  BigInt operator%(const BigInt &n) const
  {
    BigInt mod(*this);
    while(mod > n)
    {
      mod -= n;
    }
    return mod;
  }
  BigInt operator%(int n) const
  {
    BigInt bn(n);
    return *this % n;
  }
  BigInt operator%(long long int n) const
  {
    BigInt bn(n);
    return *this % n;
  }
  BigInt& operator%=(const BigInt &n)
  {
    *this = *this % n;
    return *this;
  }
  BigInt& operator%=(int n)
  {
    BigInt bn(n);
    *this = *this % bn;
    return *this;
  }
  BigInt& operator%=(long long int n)
  {
    BigInt bn(n);
    *this = *this % bn;
    return *this;
  }
  BigInt& operator=(const BigInt &n)
  {
    numvec.clear();
    std::copy(n.numvec.begin(), n.numvec.end(), std::back_inserter(numvec));
    sign = n.sign;
    return *this;
  }
  BigInt& operator=(int n)
  {
    BigInt bn(n);
    return *this = bn;
  }
  BigInt& operator=(long long int n)
  {
    BigInt bn(n);
    return *this = bn;
  }
  bool operator==(const BigInt &n) const
  {
    return !Compare(n);
  }
  bool operator!=(const BigInt &n) const
  {
    return Compare(n);
  }
  bool operator>(const BigInt &n) const
  {
    return Compare(n) > 0;
  }
  bool operator>=(const BigInt &n) const
  {
    return Compare(n) >= 0;
  }
  bool operator<(const BigInt &n) const
  {
    return Compare(n) < 0;
  }
  bool operator<=(const BigInt &n) const
  {
    return Compare(n) <= 0;
  }
  std::vector<int> numvec;
  bool sign;
};

std::ostream& operator<<(std::ostream &os, const BigInt &n)
{
  if(n.sign) os << '-';
  for(auto itr = n.numvec.rbegin(); itr != n.numvec.rend(); ++itr)
    os << *itr;
  return os;
}

BigInt operator+(int a, BigInt& b)
{
  return b + a;
}

BigInt operator-(int a, BigInt& b)
{
  return b - a;
}

BigInt operator*(int a, BigInt& b)
{
  return b * a;
}
