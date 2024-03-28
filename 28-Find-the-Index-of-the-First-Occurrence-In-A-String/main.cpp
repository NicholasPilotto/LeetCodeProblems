#include <iostream>

using std::string;

class Solution {
  public:
    static int strStr(string haystack, string needle) {
      return haystack.find(needle);
    }
};

int main() {
  string haystack = "leetcode";
  string needle = "sad";

  std::cout << Solution::strStr(haystack, needle) << '\n';

  return 0;
}
