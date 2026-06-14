// You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :
// (r+1, c-1) — move diagonally to the left.
// (r+1, c) — move directly down.
// (r+1, c+1) — move diagonally to the right.
// Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.

// Examples :
// Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
// Output: 15
// Explaination: The best path is (0, 1) -> (1, 2) -> (2, 1). It gives the maximum sum as 15.

// Input: mat[][] = [[2, 1, 1], [1, 2, 2]]
// Output: 4
// Explaination: The best path is (0, 0) -> (1, 1). It gives the maximum sum as 4.

// Input: mat[][] = [[25]]
// Output: 25
// Explaination: (0, 0) is the only cell in mat[][], so maximum path sum will be 25.

// Constraints:
// 1 ≤ mat.size() ≤ 500
// 1 ≤ mat[i].size() ≤ 500
// 1 ≤ mat[i][j] ≤ 1000

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.bruteforce
//TC:
//SC:


class Solution {
  public:
    int dfs(int i, int j , int n,int m,vector<vector<int>>& mat){
        
        if( j < 0 || j >= m ){
            return -1e8;
        }
        if(i == n-1){
            return mat[i][j];
        }
        int leftdiagonal = dfs(i+1,j-1,n,m,mat) + mat[i][j];
        int down = dfs(i+1,j,n,m,mat) + mat[i][j];
        int rightdiagonal = dfs(i+1,j+1,n,m,mat) + mat[i][j];
        return max(leftdiagonal,max(down,rightdiagonal));
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MIN;
        for(int j = 0; j<m ; j++){
         ans = max(ans,dfs(0,j,n,m,mat));
        }
        return ans;
    }
};

//2.Memoization
//TC:
//SC:
// User function Template for C++

class Solution {
  public:
    int dfs(int i, int j , int n,int m,vector<vector<int>>& mat, vector<vector<int>>& dp){
        
        if( j < 0 || j >= m ){
            return -1e8;
        }
        if(i == n-1){
            return mat[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int leftdiagonal = dfs(i+1,j-1,n,m,mat,dp) + mat[i][j];
        int down = dfs(i+1,j,n,m,mat,dp) + mat[i][j];
        int rightdiagonal = dfs(i+1,j+1,n,m,mat,dp) + mat[i][j];
        return dp[i][j] = max(leftdiagonal,max(down,rightdiagonal));
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = INT_MIN;
        for(int j = 0; j<m ; j++){
         ans = max(ans,dfs(0,j,n,m,mat,dp));
        }
        return ans;
    }
};

//3.Tabulation
//TC:
//SC:




