#include <iostream>
int arr[10], t, count_a, count_b;
int main()
{
  for(int i = 0; i < 10; ++i)
  {
    std::cin >> arr[i];
  }
  for(int i = 0; i < 10; ++i)
  {
    std::cin >> t;
    if(arr[i] > t) count_a += 1;
    if(arr[i] < t) count_b += 1;
  }
  std::cout << (count_a > count_b ? 'A' : count_a < count_b ? 'B' : 'D') << "\n";
}
