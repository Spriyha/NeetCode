// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:
// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.

// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.

// Constraints:
// 1 ≤ arr.size() ≤ 103
// 0 ≤ arr[i] ≤ 103
// 0 ≤ target ≤ 103

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC: O(2^N)
//SC: O(N*Sum) 

class Solution {
  public:
    int dfs(int i,int target,vector<int>& arr,int n){
        if(i == n){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int notTake = dfs(i+1,target,arr,n);
        int take = 0;
        if(arr[i] <= target){
            take = dfs(i+1,target-arr[i],arr,n);
        }
        return notTake + take;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return dfs(0,target,arr,n);
    }
};

//2.Memoization
//TC: O(N*Sum)
//SC: O(N*Sum) + O(N)

class Solution {
  public:
    int dfs(int i,int target,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(i == n){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = dfs(i+1,target,arr,n,dp);
        int take = 0;
        if(arr[i] <= target){
            take = dfs(i+1,target-arr[i],arr,n,dp);
        }
        return dp[i][target] = notTake + take;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return dfs(0,target,arr,n,dp);
    }
};


//Tabulation
//TC: O(N*Sum)
//SC: O(N*Sum)


class Solution {
  public:
    int dfs(int i,int sum,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(i == n){
            if(sum == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i+1,sum,arr,n,dp);
        int take = 0;
        if(arr[i] <= sum){
            take = dfs(i+1,sum-arr[i],arr,n,dp);
        }
        return dp[i][sum] = notTake + take;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[n][0] = 1;
        for(int i = n-1; i>=0; i--){
            for(int sum = 0 ; sum <= target; sum++){
                int notTake = dp[i+1][sum];
                int take = 0;
                if(arr[i] <= sum){
                    take = dp[i+1][sum-arr[i]];
                }
                dp[i][sum] = notTake + take;
                
            }
        }
        return dp[0][target];
    }
};

//Space Optimized
//TC: O(N*Sum)
//SC: O(Sum) + O(Sum)

class Solution {
  public:
    int dfs(int i,int sum,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(i == n){
            if(sum == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = dfs(i+1,sum,arr,n,dp);
        int take = 0;
        if(arr[i] <= sum){
            take = dfs(i+1,sum-arr[i],arr,n,dp);
        }
        return dp[i][sum] = notTake + take;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int>curr(target+1,0),next(target+1,0);
        next[0] = 1;
        for(int i = n-1; i>=0; i--){
            for(int sum = 0 ; sum <= target; sum++){
                int notTake = next[sum];
                int take = 0;
                if(arr[i] <= sum){
                    take = next[sum-arr[i]];
                }
                curr[sum] = notTake + take;
                
            }
            next = curr;
        }
        return next[target];
    }
};