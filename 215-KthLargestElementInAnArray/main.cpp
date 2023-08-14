#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::priority_queue;
using std::vector;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (const auto& num : nums) {
      maxHeap.push(num);
    }

    while (k != 1) {
      maxHeap.pop();
      --k;
    }

    return maxHeap.top();
  }
};

int main() {
  vector<int> nums = {3,2,3,1,2,4,5,5,6,};
  int k = 4;
  Solution s;

  cout << s.findKthLargest(nums, k);

  return 0;
}
