// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: m = 3, n = 7
// Output: 28

// Example 2:
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
 
// Constraints:
// 1 <= m, n <= 100

#include<iostream>
#include<bits/stdc++.h>
using nmaespace std;

//1.BruteForce: Recursion
//TC: O(2^N*M)
//SC: O(N + M)

class Solution {
public:
    int dfs(int i, int j, int m , int n){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i == m || j == n){
            return 0;
        }
        int down = dfs(i+1,j,m,n);
        int right = dfs(i,j+1,m,n);
        return down + right;
    }
    int uniquePaths(int m, int n) {
        return dfs(0,0,m,n);
        
    }
};

//2.Memoization
//TC: O(N * M)
//SC: O(N+M)stack + o(n*m)dp

class Solution {
public:
    int dfs(int i, int j, int m , int n,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i == m || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,dp);
        int right = dfs(i,j+1,m,n,dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dfs(0,0,m,n,dp);
        
    }
};

//3.Tabulation
//TC: O(N*M)
//SC: O(N*M)Dp

class Solution {
public:
    int dfs(int i, int j, int m , int n,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i == m || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,dp);
        int right = dfs(i,j+1,m,n,dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    continue;
                }
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                dp[i][j] = down + right;

            }
        }
        return dp[0][0];
        
    }
};
//Space Optimized
//TC: O(N*M)
//SC: O(N+1)

class Solution {
public:
    int dfs(int i, int j, int m , int n,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i == m || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(i+1,j,m,n,dp);
        int right = dfs(i,j+1,m,n,dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<int>curr(n+1,0),next(n+1,0);
        curr[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    continue;
                }
                int down = next[j];
                int right = curr[j+1];
                curr[j] = down + right;

            }
            next = curr;
        }
        return next[0];
        
    }
};
