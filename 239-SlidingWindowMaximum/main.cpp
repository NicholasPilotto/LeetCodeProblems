#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::deque;
using std::priority_queue;
using std::vector;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k            = 3;
  Solution s;

  for (const auto& r : s.maxSlidingWindow(nums, k)) {
    cout << r << " ";
  }

  return 0;
}
