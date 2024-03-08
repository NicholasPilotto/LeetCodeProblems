#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Solution {
 public:
  static double myPow(double x, int64_t n) { return pow(x, n); }

 private:
  static double pow(double x, int64_t n) {

    if (n == 0) {
      return 1;
    }

    if (n < 0) {
      x =  1 / x ;
      n = std::abs(n);
    }

    double splitted_problem = pow(x, n / 2);

    if (n % 2 == 0) {
      return splitted_problem * splitted_problem;
    }

    return x * splitted_problem * splitted_problem;
  }
};

int main() {
  double x;
  int16_t n;

  cout << "Insert x number: ";
  cin >> x;

  cout << "Insert n number: ";
  cin >> n;

  cout << "Solution is: " << Solution::myPow(x, n);

  return 0;
}
