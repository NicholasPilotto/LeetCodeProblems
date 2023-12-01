#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string w1;
    string w2;

    for (auto it = word1.cbegin(); it != word1.cend(); ++it) {
      w1.append(*it);
    }

    for (auto it = word2.cbegin(); it != word2.cend(); ++it) {
      w2.append(*it);
    }

    return w1 == w2;
  }
};

int main() {
  return 0;
}
