#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Solution {
 public:
  static double myPow(double x, long long n) { return pow(x, n); }

 private:
  static double pow(double x, long long n) {

    if (n == 0) {
      return 1;
    }

    if (n < 0) {
      x =  1 / x ;
      n = std::abs(n);
    }

    double splittedProblem = pow(x, n / 2);

    if (n % 2 == 0) {
      return splittedProblem * splittedProblem;
    }

    return x * splittedProblem * splittedProblem;
  }
};

int main() {
  double x;
  long long n;

  cout << "Insert x number: ";
  cin >> x;

  cout << "Insert n number: ";
  cin >> n;

  cout << "Solution is: " << Solution::myPow(x, n);

  return 0;
}
