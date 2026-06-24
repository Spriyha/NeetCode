// Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).
// The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.
// Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

// Examples :
// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103

#incude<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC: O(2^N)
//SC: O(N)

class Solution {
  public:
    int dfs(int i,int W,vector<int>& wt,vector<int>& val,int n){
        if(i == n){
            return 0;
        }
        int notTake = dfs(i+1,W,wt,val,n);
        int take = 0;
        if(wt[i] <= W){
            take =  val[i] + dfs(i+1,W-wt[i],wt,val,n);
        }
        return max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        return dfs(0,W,wt,val,n);
    }
};

//2.Memoization
//TC: O(N*W)
//SC: O(N * W) + O(N)

class Solution {
  public:
    int dfs(int i,int W,vector<int>& wt,vector<int>& val,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        int notTake = dfs(i+1,W,wt,val,n,dp);
        int take = 0;
        if(wt[i] <= W){
            take =  val[i] + dfs(i+1,W-wt[i],wt,val,n,dp);
        }
        return dp[i][W] = max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return dfs(0,W,wt,val,n,dp);
    }
};


//3.Tabulation
//TC: O(N*W)
//SC: O(N * W) 

class Solution {
  public:
    int dfs(int i,int Wt,vector<int>& wt,vector<int>& val,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][Wt] != -1){
            return dp[i][Wt];
        }
        int notTake = dfs(i+1,Wt,wt,val,n,dp);
        int take = 0;
        if(wt[i] <= Wt){
            take =  val[i] + dfs(i+1,Wt-wt[i],wt,val,n,dp);
        }
        return dp[i][Wt] = max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        for(int w = 0; w <= W; w++){     // this code is not required as we have already handled the base case in dp
            dp[n][w] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for(int Wt = 0; Wt <= W; Wt++){
                int notTake = dp[i+1][Wt];
                int take = 0;
                if(wt[i] <= Wt){
                    take =  val[i] + dp[i+1][Wt-wt[i]];
                }
                dp[i][Wt] = max(take,notTake);
            }
        }
        return dp[0][W];
    }
};


//SpaceOptimized
//TC: O(N*W)
//SC: O(W)

class Solution {
  public:
    int dfs(int i,int Wt,vector<int>& wt,vector<int>& val,int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][Wt] != -1){
            return dp[i][Wt];
        }
        int notTake = dfs(i+1,Wt,wt,val,n,dp);
        int take = 0;
        if(wt[i] <= Wt){
            take =  val[i] + dfs(i+1,Wt-wt[i],wt,val,n,dp);
        }
        return dp[i][Wt] = max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<int>curr(W+1,0),next(W+1,0);
        for(int i = n-1; i >= 0; i--){
            for(int Wt = 0; Wt <= W; Wt++){
                int notTake = next[Wt];
                int take = 0;
                if(wt[i] <= Wt){
                    take =  val[i] + next[Wt-wt[i]];
                }
                curr[Wt] = max(take,notTake);
            }
            next = curr;
        }
        return next[W];
    }
};