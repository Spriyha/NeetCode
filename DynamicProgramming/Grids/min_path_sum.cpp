// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200
 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC: o(2^n*m)
//SC: o(N + m)

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& grid){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i == m || j == n){
            return 1e8;
        }
        int down = grid[i][j] + dfs(i+1,j,m,n,grid);
        int right = grid[i][j] + dfs(i,j+1,m,n,grid);
        return min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return dfs(0,0,m,n,grid);
    }
};

//2.Memoization
//TC: o(N * M)
//SC: o(n+m)stack + o(n*m)dp
class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i == m || j == n){
            return 1e8;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        int down = grid[i][j] + dfs(i+1,j,m,n,grid,dp);
        int right = grid[i][j] + dfs(i,j+1,m,n,grid,dp);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dfs(0,0,m,n,grid,dp);
    }
};

//3.Tabulation
//TC: o(n*m)
//SC: dp(n*m)


class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i == m || j == n){
            return 1e8;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        int down = grid[i][j] + dfs(i+1,j,m,n,grid,dp);
        int right = grid[i][j] + dfs(i,j+1,m,n,grid,dp);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,1e8));
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if( i == m-1 && j == n-1){
                    continue;
                }
                int down = grid[i][j] + dp[i+1][j];
                int right = grid[i][j] + dp[i][j+1];
                dp[i][j] = min(down,right);
            }
        }
        return dp[0][0];
    }
};

//4.Space Optimized 
//TC: o(n*m)
//SC: o(n+1)

class Solution {
public:
    int dfs(int i, int j, int m, int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i == m || j == n){
            return 1e8;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        int down = grid[i][j] + dfs(i+1,j,m,n,grid,dp);
        int right = grid[i][j] + dfs(i,j+1,m,n,grid,dp);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>curr(n+1,1e8),next(n+1,1e8);
        curr[n-1] = grid[m-1][n-1];
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if( i == m-1 && j == n-1){
                    continue;
                }
                int down = grid[i][j] + next[j];
                int right = grid[i][j] + curr[j+1];
                curr[j] = min(down,right);
            }
            next = curr;
        }
        return next[0];
    }
};