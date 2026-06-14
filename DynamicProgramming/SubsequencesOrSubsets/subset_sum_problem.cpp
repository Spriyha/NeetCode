// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

// Examples:
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.

// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 104


#include<iosttream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC:  O(2^n)
//SC: O(n)

class Solution {
  public:
    bool dfs(int i, int sum, vector<int>& arr, int n){
        if(sum == 0){
            return true;
        }
        if(i == n){
            if(sum == 0){
                return true;
            }
            else{
                return false;
            }
        }
        bool notTake = dfs(i+1,sum,arr,n);
        bool take = false;
        if(arr[i] <= sum){
            take = dfs(i+1,sum-arr[i],arr,n);
        }
        return notTake || take;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return dfs(0,sum,arr,n);
    }
};

//2.Memoization
//TC: O(N*Sum)
//SC: O(N*Sum) + O(N)


class Solution {
  public:
    bool dfs(int i, int sum, vector<int>& arr, int n,vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(i == n){
            if(sum == 0){
                return true;
            }
            else{
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
        return dp[i][sum] = notTake || take;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return dfs(0,sum,arr,n,dp);
    }
};

//Tabulation
//TC: O(N*Sum)
//SC: O(N*Sum)

class Solution {
  public:
    bool dfs(int i, int tar, vector<int>& arr, int n,vector<vector<int>>& dp){
        if(tar == 0){
            return true;
        }
        if(i == n){
            if(tar == 0){
                return true;
            }
            else{
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
        return dp[i][tar] = notTake || take;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,false));
        for(int i = 0; i <n; i++){
            dp[i][0] = true;
        }
        dp[n][0] = true;
        for(int i = n-1; i>=0; i--){
            for(int tar = 0 ; tar <= sum ; tar++){
                bool notTake = dp[i+1][tar];
                bool take = false;
                if(arr[i] <= tar){
                    take = dp[i+1][tar-arr[i]];
                }
                dp[i][tar] = notTake || take; 
            }
        }
        return dp[0][sum];
    }
};


//Space Optimized
//TC: O(N*Sum)
//SC: O(Sum) + O(Sum)

class Solution {
  public:
    bool dfs(int i, int tar, vector<int>& arr, int n,vector<vector<int>>& dp){
        if(tar == 0){
            return true;
        }
        if(i == n){
            if(tar == 0){
                return true;
            }
            else{
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
        return dp[i][tar] = notTake || take;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<int>curr(sum+1,false),next(sum+1,false);
        next[0] = true;
        for(int i = n-1; i>=0; i--){
            for(int tar = 0 ; tar <= sum ; tar++){
                bool notTake = next[tar];
                bool take = false;
                if(arr[i] <= tar){
                    take = next[tar-arr[i]];
                }
                curr[tar] = notTake || take; 
            }
            next = curr;
        }
        return next[sum];
    }
};