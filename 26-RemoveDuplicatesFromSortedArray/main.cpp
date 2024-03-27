#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    static int removeDuplicates(vector<int>& nums) {
      vector<int> tmp;

      for (int num : nums) {
        if (tmp.empty() || tmp.back() != num) {
          tmp.push_back(num);
        }

        num = 101;
      }

      std::copy(tmp.data(), tmp.data() + tmp.size(), nums.begin());

      return tmp.size();
    }
};

int main() {
  vector<int> nums = {1, 2};

  std::cout << Solution::removeDuplicates(nums) << '\n';
  return 0;
}
