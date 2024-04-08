#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = 0;
      int y = 0;

      while (i < m) {
        while (y < n) {
          if (nums1[i] >= nums2[y]) {
            nums1.insert(nums1.begin() + i, nums2.begin() + y, nums2.begin() + y);
            ++y;
          } else if (nums1[i] < nums2[y]) {
            ++i;
          }
        }
      }
    }
};

int main() {
  vector<int> nums1 = { 1,2,3,0,0,0 };
  vector<int> nums2 = { 2,5,6 };

  Solution::merge(nums1, nums1.size(), nums2, nums2.size());

  for (const int n : nums1) {
    std::cout << n << ' ';
  }

  std::cout << '\n';
  return 0;
}

/**
1 2 2 3
2 3 4 5


*/
