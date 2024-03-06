#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
      map<int,int>mp;
      int count = 0 ;

      for( int i = 0 ; i < nums.size() ; i++ ) {
        mp[ nums[i] ]++;
      }

      for( int i = 0 ; i < nums.size() ; i++ ) {
          if ( mp[nums[i]+diff] && mp[nums[i]+diff+diff]) {
            count++;
          }
      }
      return count;
    }
};

int main() {
  vector<int> nums = {0,1,4,6,7,10};
  int diff = 3;

  Solution s;

  std::cout << s.arithmeticTriplets(nums, diff) << '\n';

  return 0;
}
