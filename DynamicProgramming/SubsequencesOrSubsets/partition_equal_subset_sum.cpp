// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
// Note: Each element must be in exactly one subset.

// Examples:
// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].

// Input: arr = [1, 3, 5]
// Output: false
// Explanation: This array can never be partitioned into two such parts.

// Constraints:
// 1 ≤ arr.size ≤ 100
// 1 ≤ arr[i] ≤ 200


#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.bruteforce : recursion
//TC: O(2^N)
//SC: O(N)

class Solution {
  public:
    int dfs(int i, int sum, vector<int>& arr,int n){
        if(sum == 0){
            return true;
        }
        if(i == n){
            if(sum == 0){
                return true;
            }
            else {
                return false;
            }
        }
        bool notTake = dfs(i+1,sum,arr,n);
        bool take = false;
        if(arr[i] <= sum){
             take = dfs(i+1,sum-arr[i],arr,n);
        }
        return take || notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        return dfs(0,target,arr,n);
    }
};

//2.Memoization
//TC: O(N*Sum)
//SC: O(N*Sum) + O(N) 

class Solution {
  public:
    int dfs(int i, int sum, vector<int>& arr,int n,vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(i == n){
            if(sum == 0){
                return true;
            }
            else {
                return false;
            }
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        bool notTake = dfs(i+1,sum,arr,n,dp);
        bool take = false;
        if(arr[i] <= sum){
             take = dfs(i+1,sum-arr[i],arr,n,dp);
        }
        return dp[i][sum] = take || notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target + 1, -1));
        return dfs(0,target,arr,n,dp);
    }
};

//3.Tabulation
//TC: O(N*Sum)
//SC: O(N*Sum)

class Solution {
  public:
    int dfs(int i, int tar, vector<int>& arr,int n,vector<vector<int>>& dp){
        if(tar == 0){
            return true;
        }
        if(i == n){
            if(tar == 0){
                return true;
            }
            else {
                return false;
            }
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        bool notTake = dfs(i+1,tar,arr,n,dp);
        bool take = false;
        if(arr[i] <= tar){
             take = dfs(i+1,tar-arr[i],arr,n,dp);
        }
        return dp[i][tar] = take || notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target + 1, false));
        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }
        dp[n][0] = true;
        for(int i = n-1; i>=0; i--){
            for(int tar = 0; tar<=target; tar++){
                bool notTake = dp[i+1][tar];
                bool take = false;
                if(arr[i] <= tar){
                     take = dp[i+1][tar-arr[i]];
                }
                dp[i][tar] = take || notTake;
            }
        }
        return dp[0][target];
    }
};

//4.SpaceOpptimization
//TC: O(N*Sum)
//SC: O(Sum) + O(Sum)

class Solution {
  public:
    int dfs(int i, int tar, vector<int>& arr,int n,vector<vector<int>>& dp){
        if(tar == 0){
            return true;
        }
        if(i == n){
            if(tar == 0){
                return true;
            }
            else {
                return false;
            }
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        bool notTake = dfs(i+1,tar,arr,n,dp);
        bool take = false;
        if(arr[i] <= tar){
             take = dfs(i+1,tar-arr[i],arr,n,dp);
        }
        return dp[i][tar] = take || notTake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<int>curr(target+1,false),next(target + 1, false);
        next[0] = true;
        for(int i = n-1; i>=0; i--){
            for(int tar = 0; tar<=target; tar++){
                bool notTake = next[tar];
                bool take = false;
                if(arr[i] <= tar){
                     take = next[tar-arr[i]];
                }
                curr[tar] = take || notTake;
            }
            next = curr;
        }
        return next[target];
    }
};

