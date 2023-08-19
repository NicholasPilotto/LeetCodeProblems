#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::pow;
using std::string;
using std::vector;

class Solution {
 public:
  string toHex(int num) {
    unsigned int tmpNumber = num;
    if (num < 0) {
      tmpNumber = static_cast<unsigned int>(num);
    }

    vector<char> hexed = {
      '0',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'a',
      'b',
      'c',
      'd',
      'e',
      'f',
    };

    unsigned int quotient  = tmpNumber;
    unsigned int remainder = tmpNumber;
    string result;

    do {
      remainder = quotient % 16;
      result.insert(result.begin(), hexed[remainder]);
      quotient = quotient / 16;
    } while (quotient != 0);

    return result;
  }
};

int main() {
  Solution s;
  cout << s.toHex(26);
  cout << '\n';
  cout << s.toHex(-1);
  return 0;
}
