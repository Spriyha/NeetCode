// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to make the change for Rs n. 

// Examples:
// Input: n = 39
// Output: 6
// Explaination: 39 can be formed using 3 coins of 10 rupees, 1 coin of 5 rupees and 2 coins of 2 rupees so minimum coins required are 6.

// Input: n = 121
// Output: 13
// Explaination: 121 can be formed using 12 coins of 10 rupees and 1 coin of 1 rupees.

// Constraints:
// 1 ≤ n ≤ 106

#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC : o(2^n)
//SC : o(N) 

class Solution {
  public:
    int dfs(int i, int x,int sum, vector<int>coins){
        if(sum == 0){
            return 0;
        }
        if(i == x){
            return 1e9;
        }
        
        
        int notTake = dfs(i + 1,x,sum,coins);
        int take = 1e9;
        if(coins[i] <= sum){
            take =  1 + dfs(i,x,sum - coins[i],coins);
        }
        return min(take,notTake);
    }
    int findMin(int n) {
        // code here
        vector<int>coins = {1,2,5,10};
        int x = coins.size();
        return dfs(0,x,n,coins);
    }
};

//2.memoization
//TC: O(N*SUM)
//SC: O(N)Stack + O(N*Sum)DP Space

class Solution {
  public:
    int dfs(int i, int x,int sum, vector<int>& coins,vector<vector<int>>& dp){
        if(sum == 0){
            return 0;
        }
        if(i == x){
            return 1e9;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i + 1,x,sum,coins,dp);
        int take = 1e9;
        if(coins[i] <= sum){
            take =  1 + dfs(i,x,sum - coins[i],coins,dp);
        }
        return dp[i][sum] = min(take,notTake);
    }
    int findMin(int n) {
        // code here
        vector<int>coins = {1,2,5,10};
        int x = coins.size();
        vector<vector<int>>dp(x+1,vector<int>(n+1,-1));
        return dfs(0,x,n,coins,dp);
    }
};

//3.Tabualation
//TC: O(N*Sum)
//SC: O(N*SUM) no stack space only dp


class Solution {
  public:
    int dfs(int i, int x,int sum, vector<int>& coins,vector<vector<int>>& dp){
        if(sum == 0){
            return 0;
        }
        if(i == x){
            return 1e9;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i + 1,x,sum,coins,dp);
        int take = 1e9;
        if(coins[i] <= sum){
            take =  1 + dfs(i,x,sum - coins[i],coins,dp);
        }
        return dp[i][sum] = min(take,notTake);
    }
    int findMin(int n) {
        // code here
        vector<int>coins = {1,2,5,10};
        int x = coins.size();
        vector<vector<int>>dp(x+1,vector<int>(n+1,1e9));
        dp[x][0] = 0;
        for(int i = x-1; i >= 0; i--){
            for(int sum = 0 ; sum <= n; sum++){
               int notTake = dp[i + 1][sum];
               int take = 1e9;
                if(coins[i] <= sum){
                    take =  1 + dp[i][sum - coins[i]];
                }
                dp[i][sum] = min(take,notTake); 
            }
        }
        return dp[0][n];
    }
};

//4.Space Optmization
//TC: O(N*SUM)
//SC: O(SUM)

class Solution {
  public:
    int dfs(int i, int x,int sum, vector<int>& coins,vector<vector<int>>& dp){
        if(sum == 0){
            return 0;
        }
        if(i == x){
            return 1e9;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i + 1,x,sum,coins,dp);
        int take = 1e9;
        if(coins[i] <= sum){
            take =  1 + dfs(i,x,sum - coins[i],coins,dp);
        }
        return dp[i][sum] = min(take,notTake);
    }
    int findMin(int n) {
        // code here
        vector<int>coins = {1,2,5,10};
        int x = coins.size();
        vector<int>curr(n+1,1e9),next(n+1,1e9);
        next[0] = 0;
        for(int i = x-1; i >= 0; i--){
            for(int sum = 0 ; sum <= n; sum++){
               int notTake = next[sum];
               int take = 1e9;
                if(coins[i] <= sum){
                    take =  1 + curr[sum - coins[i]];
                }
                curr[sum] = min(take,notTake); 
            }
            next = curr;
        }
        return next[n];
    }
};









