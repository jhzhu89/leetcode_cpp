//
// Created by Neptune on 5/2/16.
//

/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers
 * on the row below.
 *
 * For example, given the following triangle
 * [
 * [2],
 * [3,4],
 * [6,5,7],
 * [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector <vector<int>> &triangle) {
        int rows = triangle.size();

        if (rows == 0) return 0;

        for (int i = rows - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j)
                triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
        }

        return triangle[0][0];
    }
};

int main() {
    vector<vector<int>> v{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << Solution().minimumTotal(v) << endl;
    return 0;
}
