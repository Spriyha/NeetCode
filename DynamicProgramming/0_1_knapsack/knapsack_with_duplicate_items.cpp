// Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
// Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

// Note: Each item can be taken any number of times.

// Examples:

// Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.

// Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 110
// Explanation: The optimal choice is to pick the 2nd element and the 4th element.

// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element. Hence, total profit is 0.

// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 1000
// 1 ≤ capacity ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100

using namespace std;
#include<iostream>
#include<bits/stdc++.h>

//1.Brute force 
//TC: O(2^N)
//SC: O(N)

class Solution {
  public:
    int dfs(int i,vector<int>& val, vector<int>& wt, int capacity, int n){
        if(i == n){
            return 0;
        }
        int notTake = dfs(i+1,val,wt,capacity,n);
        int take = 0 ;
        if(wt[i] <= capacity){
            take = val[i] + dfs(i,val,wt,capacity - wt[i],n);
        }
        return max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        return dfs(0,val,wt,capacity,n);
    }
};

//2.Memoization
//TC : O(N*W)
//SC : O(N*W) + O(N)

class Solution {
  public:
    int dfs(int i,vector<int>& val, vector<int>& wt, int capacity, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][capacity] != -1){
            return dp[i][capacity];
        }
        int notTake = dfs(i+1,val,wt,capacity,n,dp);
        int take = 0 ;
        if(wt[i] <= capacity){
            take = val[i] + dfs(i,val,wt,capacity - wt[i],n,dp);
        }
        return dp[i][capacity] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity + 1,-1));
        return dfs(0,val,wt,capacity,n,dp);
    }
};

//3.Tabulation
//TC: O(N*W)
//SC: O(N*W)

class Solution {
  public:
    int dfs(int i,vector<int>& val, vector<int>& wt, int w, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][w] != -1){
            return dp[i][w];
        }
        int notTake = dfs(i+1,val,wt,w,n,dp);
        int take = 0 ;
        if(wt[i] <= w){
            take = val[i] + dfs(i,val,wt,w - wt[i],n,dp);
        }
        return dp[i][w] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity + 1,0));
        for(int w = 0 ; w <= capacity; w++){ // this code is not required as we have already handled the base case in dp
            dp[n][w] = 0;
        }
        for(int i = n-1; i >=0 ; i--){
            for(int w = 0; w <= capacity ; w++){
                int notTake = dp[i+1][w];
                int take = 0 ;
                if(wt[i] <= w){
                    take = val[i] + dp[i][w - wt[i]];
                }
                dp[i][w] = max(take, notTake);
            }
        }
        
        return dp[0][capacity];
    }
};

//4.Space optimized
//TC: O(N*W)
//SC: O(W)

class Solution {
  public:
    int dfs(int i,vector<int>& val, vector<int>& wt, int w, int n,vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i][w] != -1){
            return dp[i][w];
        }
        int notTake = dfs(i+1,val,wt,w,n,dp);
        int take = 0 ;
        if(wt[i] <= w){
            take = val[i] + dfs(i,val,wt,w - wt[i],n,dp);
        }
        return dp[i][w] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<int>curr(capacity + 1,0),next(capacity + 1,0);
        for(int i = n-1; i >=0 ; i--){
            for(int w = 0; w <= capacity ; w++){
                int notTake = next[w];
                int take = 0 ;
                if(wt[i] <= w){
                    take = val[i] + curr[w - wt[i]];
                }
                curr[w] = max(take, notTake);
            }
            next = curr;
        }
        
        return next[capacity];
    }
};








