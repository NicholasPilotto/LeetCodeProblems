#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
      int founds = 0;
      for (auto it = nums.begin(); it != nums.end() - founds; ++it) {
        if (*it == val) {
          ++founds;
          --it;
          std::rotate(it, it + 1, nums.end());
        }
      }

      return nums.size() - founds;
    }
};

int main() {
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;


  std::cout << Solution::removeElement(nums, val) << '\n';
  return 0;
}
