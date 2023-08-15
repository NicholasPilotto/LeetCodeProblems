#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::pair;
using std::vector;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> rowsValue{};
    vector<int> result{};

    int i   = 0;
    int sum = 0;

    for (auto itx = mat.cbegin(); itx != mat.cend(); ++itx) {
      for (auto ity = (*itx).cbegin(); ity != (*itx).cend(); ++ity) {
        if (*ity == 1) {
          ++sum;
        }
      }
      rowsValue.push_back(std::make_pair(i, sum));
      ++i;
      sum = 0;
    }

    std::sort(rowsValue.begin(), rowsValue.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return (lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first));
    });

    for (int i = 0; i < k && i < rowsValue.size(); ++i) {
      result.push_back(rowsValue[i].first);
    }

    return result;
  }
};

int main() {
  vector<vector<int>> mat = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1}
  };
  int k = 3;
  Solution s;

  auto result = s.kWeakestRows(mat, k);

  for (const auto& r : result) {
    cout << r << "\n";
  }
  return 0;
}
