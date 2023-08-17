#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::pair;
using std::queue;
using std::vector;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int matrixSize = mat.size();
    int rowSize    = mat[0].size();

    vector<vector<int>> dp(matrixSize, vector<int>(rowSize, -1));
    queue<pair<int, int>> queue;

    for (int i = 0; i < matrixSize; i++) {
      for (int j = 0; j < rowSize; j++) {
        if (mat[i][j] == 0) {
          queue.push({i, j});
          dp[i][j] = 0;
        }
      }
    }

    while (!queue.empty()) {
      auto [i, j] = queue.front();
      queue.pop();
      int d                      = dp[i][j];
      vector<pair<int, int>> adj = {
        {i,     j + 1},
        {i + 1, j    },
        {i,     j - 1},
        {i - 1, j    }
      };
      for (auto [a, b] : adj) {
        if (a < 0 || a >= matrixSize || b < 0 || b >= rowSize || dp[a][b] != -1) {
          continue;
        }
        queue.push({a, b});
        dp[a][b] = d + 1;
      }
    }
    return dp;
  }
};

int main() {
  vector<vector<int>> mat = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1}
  };

  Solution s;

  auto result = s.updateMatrix(mat);
  for (const auto& rows : result) {
    for (const auto& columns : rows) {
      cout << columns << " ";
    }
    cout << "\n";
  }

  return 0;
}
