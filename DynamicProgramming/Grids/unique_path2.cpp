// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:
// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1
 
// Constraints:
// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.
 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce:Recursion
//TC: O(2^N*M)
//SC: O(N+M)

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& obstacleGrid){
        if(i == m || j == n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        int down = dfs(i+1,j,m,n,obstacleGrid);
        int right = dfs(i,j+1,m,n,obstacleGrid);
        return down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        return dfs(0,0,m,n,obstacleGrid);
        
    }
};

//2.memoization
//TC: O(N*M)
//SC: O(N+M) + Dp O(n*m)

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i == m || j == n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,obstacleGrid,dp);
        int right = dfs(i,j+1,m,n,obstacleGrid,dp);
        return dp[i][j] = down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dfs(0,0,m,n,obstacleGrid,dp);
        
    }
};

//3.Tabulation
//TC: O(N*M)
//SC: O(N*M)DP

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i == m || j == n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,obstacleGrid,dp);
        int right = dfs(i,j+1,m,n,obstacleGrid,dp);
        return dp[i][j] = down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    if(obstacleGrid[i][j] == 1){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                long long down = dp[i+1][j];
                long long right = dp[i][j+1];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];  
    }
};

//4.spaceOptimized
//TC: o(n*m)
//SC: o(n)

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i == m || j == n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,obstacleGrid,dp);
        int right = dfs(i,j+1,m,n,obstacleGrid,dp);
        return dp[i][j] = down + right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<long long> curr(n + 1, 0),next(n+1,0);
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    if(obstacleGrid[i][j] == 1){
                        curr[j] = 0;
                    }
                    else{
                        curr[j] = 1;
                    }
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                long long down = next[j];
                long long right = curr[j+1];
                curr[j] = down + right;
            }
            next = curr;
        }
        return next[0];  
    }
};