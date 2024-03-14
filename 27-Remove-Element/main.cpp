#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    static int removeElement(vector<int>& nums, int val) {
      if (nums.empty()) {
        return 0;
      }

      int founds = 0;
      int i = 0;
      int j = nums.size() - 1;

      while (i < j) {
        while (i < j && nums[j] == val) {
          j--;
        }
        if (nums[i] == val) {
          std::swap(nums[i], nums[j]);
        }
        i++;
      }

      for (const auto& v : nums) {
        if (v != val) {
          ++founds;
        }
      }

      return founds;
    }
};

int main() {
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int val = 2;

  std::cout << Solution::removeElement(nums, val) << '\n';

  for (const auto& n : nums) {
    std::cout << n << ' ';
  }

  return 0;
}
