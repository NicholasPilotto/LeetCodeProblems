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
          if (nums1[i] <= nums2[y]) {
            ++i;
          } else if (nums1[i] > nums2[y]) {
            nums1.insert(nums1.begin() + i, nums2.begin() + y, )
          }
        }
      }
    }
};

int main() {
  return 0;
}

/**
1 2 2 3
2 3 4 5


*/
