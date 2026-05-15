// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
 
#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce:Recursion
//TC: O(2^N)
//SC: O(N)

class Solution {
public:
    int dfs(int i,int n, vector<int>& nums){
        if(i>=n){
            return 0;
        }
        int left = dfs(i+1,n,nums);
        int right = nums[i] + dfs(i+2,n,nums);
        return max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return dfs(0,n,nums);
    }
};

//2.Optimized:memoization
//TC: O(N)
//SC: o(N) + Stack o(n)

class Solution {
public:
    int dfs(int i,int n, vector<int>& nums,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,nums,dp);
        int right = nums[i] + dfs(i+2,n,nums,dp);
        return dp[i] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2,-1);
        return dfs(0,n,nums,dp);
    }
};


//3.Optimized:tabulation
//TC: O(N)
//SC: o(N)

class Solution {
public:
    int dfs(int i,int n, vector<int>& nums,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,nums,dp);
        int right = nums[i] + dfs(i+2,n,nums,dp);
        return dp[i] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2,0);
        for(int i = n-1;i>=0;i--){
            int left = dp[i+1];
            int right = nums[i] + dp[i+2];
            dp[i] = max(left,right);
        }
        return dp[0];
    }
};

//4.space Optimized
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int dfs(int i,int n, vector<int>& nums,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,nums,dp);
        int right = nums[i] + dfs(i+2,n,nums,dp);
        return dp[i] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next = 0, next2 = 0;
        for(int i = n-1;i>=0;i--){
            int left = next;
            int right = nums[i] + next2;
            int curr = max(left,right);
            next2 = next;
            next = curr;
        }
        return next;
    }
};