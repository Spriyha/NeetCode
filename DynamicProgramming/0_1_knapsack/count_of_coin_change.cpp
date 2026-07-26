// Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
// Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
// Answers are guaranteed to fit into a 32-bit integer. 

// Examples:
// Input: coins[] = [1, 2, 3], sum = 4
// Output: 4
// Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].

// Input: coins[] = [2, 5, 3, 6], sum = 10
// Output: 5
// Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].

// Input: coins[] = [5, 10], sum = 3
// Output: 0
// Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.

// Constraints:
// 1 <= sum <= 103
// 1 <= coins[i] <= 104
// 1 <= coins.size() <= 103

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.Brute
//TC: O(2^N)
//SC: O(N) Stack space


class Solution {
  public:
    int dfs(int i,vector<int>& coins, int sum, int n){
        if(i == n){
            return 0;
        }
        if(sum == 0){
            return 1;
        }
        int notTake = dfs(i+1,coins,sum,n);
        int take = 0;
        if(coins[i] <= sum){
            take = dfs(i,coins,sum - coins[i], n);
        }
        return take + notTake;
        
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        return dfs(0,coins,sum,n);
    }
};

//2.memoization
//TC: O(N*SUM)
//SC: O(N)Stack + O(N*Sum)DP Space


class Solution {
  public:
    int dfs(int i,vector<int>& coins, int sum, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(sum == 0){
            return 1;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i+1,coins,sum,n,dp);
        int take = 0;
        if(coins[i] <= sum){
            take = dfs(i,coins,sum - coins[i], n,dp);
        }
        return dp[i][sum] = take + notTake;
        
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum +1, -1));
        return dfs(0,coins,sum,n,dp);
    }
};

//3.Tabualation
//TC: O(N*Sum)
//SC: O(N*SUM) no stack space only dp

class Solution {
  public:
    int dfs(int i,vector<int>& coins, int target, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = dfs(i+1,coins,target,n,dp);
        int take = 0;
        if(coins[i] <= target){
            take = dfs(i,coins,target - coins[i], n,dp);
        }
        return dp[i][target] = take + notTake;
        
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum +1, 0));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i = n-1; i>=0 ; i--){
            for(int target = 0; target <= sum; target++){
                int notTake = dp[i+1][target];
                int take = 0;
                if(coins[i] <= target){
                    take = dp[i][target - coins[i]];
                }
                dp[i][target] = take + notTake;
            }
        }
        
        
        return dp[0][sum];
        
    }
};


//4.Space Optmization
//TC: O(N*SUM)
//SC: O(SUM)

class Solution {
  public:
    int dfs(int i,vector<int>& coins, int target, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = dfs(i+1,coins,target,n,dp);
        int take = 0;
        if(coins[i] <= target){
            take = dfs(i,coins,target - coins[i], n,dp);
        }
        return dp[i][target] = take + notTake;
        
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int>curr(sum + 1,0),next(sum +1, 0);
    //    for(int i = 0; i<=n; i++){
            next[0] = 1;
     //   }
        for(int i = n-1; i>=0 ; i--){
            for(int target = 0; target <= sum; target++){
                int notTake = next[target];
                int take = 0;
                if(coins[i] <= target){
                    take = curr[target - coins[i]];
                }
                curr[target] = take + notTake;
            }
            next = curr;
        }
        
        
        return next[sum];
        
    }
};


