#include <iostream>
#include <vector>
#include <algorithm>
int
main() {
  int n,k,buf;
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> k;
  std::vector<int> nums;
  for(int i=0;i<n;i++) {
    std::cin >> buf;
    nums.push_back(buf);
  }
  std::nth_element(nums.begin(), nums.begin()+k-1, nums.end());
  std::cout << *(nums.begin()+k-1) << "\n";
}
