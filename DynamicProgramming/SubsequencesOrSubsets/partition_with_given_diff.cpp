// Given an array arr[] and an integer diff, count the number of ways to partition the array into two subsets such that the difference between their sums is equal to diff.
// Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

// Examples :
// Input: arr[] = [5, 2, 6, 4], diff = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : [6, 4], [5, 2]. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

// Input: arr[] = [1, 1, 1, 1], diff = 0 
// Output: 6 
// Explanation: We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3] and put them in sum1 and remaning two 1's in sum2.
// Thus there are total 6 ways for partition the array arr. 

// Input: arr[] = [3, 2, 7, 1], diff = 4  
// Output: 0
// Explanation: There is no possible partition of the array that satisfy the given difference. 

// Constraint:
// 1 ≤ arr.size() ≤ 50
// 0 ≤ diff ≤ 50
// 0 ≤ arr[i] ≤ 6

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForc
//TC: O(2^N)
//SC: O(N)

class Solution {
  public:
    int dfs(int i , int tar , vector<int>& arr, int n){
        if(i == n){
            if(tar == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int notTake = dfs(i+1,tar,arr,n);
        int take = 0;
        if(arr[i] <= tar){
            take = dfs(i+1,tar-arr[i],arr,n);
        }
        return take + notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        sum += diff;
        if(sum & 1){
            return 0;
        }
        int target = sum;
        return dfs(0,target,arr,n);
    }
        
    
};

//2.Memoization
//TC: O(N * Sum)
//SC: O(N * Sum) + O(N)

class Solution {
  public:
    int dfs(int i , int tar , vector<int>& arr, int n, vector<vector<int>>& dp){
        if(i == n){
            if(tar == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = dfs(i+1,tar,arr,n,dp);
        int take = 0;
        if(arr[i] <= tar){
            take = dfs(i+1,tar-arr[i],arr,n,dp);
        }
        return dp[i][tar] = take + notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum + diff < 0){
            return 0;
        }
        if((sum + diff) % 2 != 0){
            return 0;
        }
        int target = 0;
        target = (sum + diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(target + 1 , -1));
        return dfs(0,target,arr,n,dp);
    }
};

//Tabulation
//TC: O(N*Sum)
//SC: O(N*Sum)

class Solution {
  public:
    int dfs(int i , int tar , vector<int>& arr, int n, vector<vector<int>>& dp){
        if(i == n){
            if(tar == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = dfs(i+1,tar,arr,n,dp);
        int take = 0;
        if(arr[i] <= tar){
            take = dfs(i+1,tar-arr[i],arr,n,dp);
        }
        return dp[i][tar] = take + notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum + diff < 0){
            return 0;
        }
        if((sum + diff) % 2 != 0){
            return 0;
        }
        int target = 0;
        target = (sum + diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(target + 1 , 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        dp[n][0] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int tar = 0; tar <= target ; tar++){
                int notTake = dp[i+1][tar];
                int take = 0;
                if(arr[i] <= tar){
                    take = dp[i+1][tar-arr[i]];
                }
                dp[i][tar] = take + notTake;
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
    int dfs(int i , int tar , vector<int>& arr, int n, vector<vector<int>>& dp){
        if(i == n){
            if(tar == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][tar] != -1){
            return dp[i][tar];
        }
        int notTake = dfs(i+1,tar,arr,n,dp);
        int take = 0;
        if(arr[i] <= tar){
            take = dfs(i+1,tar-arr[i],arr,n,dp);
        }
        return dp[i][tar] = take + notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + arr[i];
        }
        if(sum + diff < 0){
            return 0;
        }
        if((sum + diff) % 2 != 0){
            return 0;
        }
        int target = 0;
        target = (sum + diff)/2;
        vector<int>curr(target+1,0),next(target + 1 , 0);
        for(int i = 0; i < n; i++){
            next[0] = 1;
        }
        next[0] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int tar = 0; tar <= target ; tar++){
                int notTake = next[tar];
                int take = 0;
                if(arr[i] <= tar){
                    take = next[tar-arr[i]];
                }
                curr[tar] = take + notTake;
            }
            next = curr;
        }
        return next[target];
    }
};
