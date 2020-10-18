//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <vector>


class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        for (int i=0; i<m; i++)     dp[i][0] = obstacleGrid[i][0] ? 0 : 1;
        for (int j=0; j<n; j++)     dp[0][j] = obstacleGrid[0][j] ? 0 : 1;

        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){
    std::vector<std::vector<int>> obstacleGrid = {{0, 0, 0},
                                                  {0, 1, 0},
                                                  {0, 0, 0}};
    Solution sol;
    assert(sol.uniquePathsWithObstacles(obstacleGrid) == 2);
    return 0;
}