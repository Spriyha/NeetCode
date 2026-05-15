// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 
// Constraints:
// 1 <= n <= 45

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC: O(2^n)
//SC: O(N)

class Solution {
public: 
    int dfs(int i){
        if(i == 0){
            return 1;
        }
        int left = dfs(i-1);
        int right = 0;
        if(i>1){
         right = dfs(i-2);
        }
        return left + right;
    }
    int climbStairs(int n) {
       return dfs(n);
    }
};


//2.Optimized:Memoization
//TC: O(N)
//SC: O(N) + Stack O(N)

class Solution {
public: 
    int dfs(int i,vector<int>&dp){
        if(i == 0){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i-1,dp);
        int right = 0;
        if(i>1){
         right = dfs(i-2,dp);
        }
        return dp[i] = left + right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return dfs(n,dp);
    }
};


//3.Optimized:Tabulation
//TC: O(N)
//SC: O(N)

class Solution {
public: 
    int dfs(int i,vector<int>&dp){
        if(i == 0){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i-1,dp);
        int right = 0;
        if(i>1){
         right = dfs(i-2,dp);
        }
        return dp[i] = left + right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i<=n ; i++){
            int left = dp[i-1];
            int right = 0;
            if(i>1){
            right = dp[i-2];
            }
             dp[i] = left + right;  
        }
       return dp[n];
    }
};

//4.space optimized
//TC: O(N)
//SC: O(1)

class Solution {
public: 
    int dfs(int i,vector<int>&dp){
        if(i == 0){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i-1,dp);
        int right = 0;
        if(i>1){
         right = dfs(i-2,dp);
        }
        return dp[i] = left + right;
    }
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 0;
        for(int i = 1; i<=n ; i++){
            int left = prev;
            int right = 0;
            if(i>1){
            right = prev2;
            }
           int curr = left + right; 
           prev2 = prev;
           prev = curr; 
        }
       return prev;
    }
};
