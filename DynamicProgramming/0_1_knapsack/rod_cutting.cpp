// Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: n = size of price, and price[] is 1-indexed array.

// Example:

// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

// Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
// Output: 24
// Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

// Input: price[] = [3]
// Output: 3
// Explanation: There is only 1 way to pick a piece of length 1.

// Constraints:
// 1 ≤ price.size() ≤ 103
// 1 ≤ price[i] ≤ 106

using namespace std;
#include<iostream>
#include<bits/stdc++.h>

//1.Brute Force
//TC: O(2^N)
//SC: O(N)

class Solution {
  public:
    int dfs(int i,vector<int> &price,int remainingLen,int n){
        if(i == n){
            return 0;
        }
        int notTake = dfs(i+1,price,remainingLen,n);
        int take = 0;
        int rodLength = i+1;
        if(rodLength <= remainingLen){
            take = price[i] + dfs(i,price,remainingLen-rodLength,n);
        }
        return max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        return dfs(0,price,n,n);
    }
};

//2.Memoization
//TC: O(N*RemainLength)
//SC: O(N) +  O(N*RemainLength)

class Solution {
  public:
    int dfs(int i,vector<int> &price,int remainingLen,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][remainingLen] != -1){
            return dp[i][remainingLen];
        }
        int notTake = dfs(i+1,price,remainingLen,n,dp);
        int take = 0;
        int rodLength = i+1;
        if(rodLength <= remainingLen){
            take = price[i] + dfs(i,price,remainingLen-rodLength,n,dp);
        }
        return dp[i][remainingLen] = max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dfs(0,price,n,n,dp);
    }
};

//3.tabulatiom
//TC: O(N*RemainLength)
//SC:  O(N*RemainLength)

class Solution {
  public:
    int dfs(int i,vector<int> &price,int remainingLen,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][remainingLen] != -1){
            return dp[i][remainingLen];
        }
        int notTake = dfs(i+1,price,remainingLen,n,dp);
        int take = 0;
        int rodLength = i+1;
        if(rodLength <= remainingLen){
            take = price[i] + dfs(i,price,remainingLen-rodLength,n,dp);
        }
        return dp[i][remainingLen] = max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int remLen = 0; remLen <= n; remLen++){
                 int notTake = dp[i+1][remLen];
                 int take = 0;
                 int rodLength = i+1;
                 if(rodLength <= remLen){
                    take = price[i] + dp[i][remLen-rodLength];
                    }
                dp[i][remLen] = max(take,notTake);
            }
        }
        return dp[0][n];
    }
};

//4.spaceOptimize
//TC:  O(N*RemainLength)
//SC: o(N+1)

class Solution {
  public:
    int dfs(int i,vector<int> &price,int remainingLen,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][remainingLen] != -1){
            return dp[i][remainingLen];
        }
        int notTake = dfs(i+1,price,remainingLen,n,dp);
        int take = 0;
        int rodLength = i+1;
        if(rodLength <= remainingLen){
            take = price[i] + dfs(i,price,remainingLen-rodLength,n,dp);
        }
        return dp[i][remainingLen] = max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>curr(n+1,0),next(n+1,0);
        for(int i = n-1; i >= 0; i--){
            for(int remLen = 0; remLen <= n; remLen++){
                 int notTake = next[remLen];
                 int take = 0;
                 int rodLength = i+1;
                 if(rodLength <= remLen){
                    take = price[i] + curr[remLen-rodLength];
                    }
               curr[remLen] = max(take,notTake);
            }
            next = curr;
        }
        return next[n];
    }
};