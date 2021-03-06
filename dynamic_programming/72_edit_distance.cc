//
// Created by Neptune on 5/2/16.
//

/*
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
 * (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 *      a) Insert a character
 *      b) Delete a character
 *      c) Replace a character
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    // table[i][j]: distance from words1.substr(0, i) to words2.substr(0, j)
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m + 1][n + 1];

        for (int i = 0; i < m + 1; ++i) dp[i][0] = i;

        for (int j = 0; j < n + 1; ++j) dp[0][j] = j;

        // table[i][j] is the min distance between the next three values
        // from table[i-1][j], table[i][j-1], or table[i-1][j-1] to table[i][j]
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j) {
                int cost = (word1[i - 1] == word2[j - 1] ? 0 : 1);
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + cost);
            }

        return dp[m][n];
    }
};

int main() {
    cout << Solution().minDistance("abc", "def") << endl;
    return 0;
}
