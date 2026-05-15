// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:
// Input: nums = [1,2,3]
// Output: 3
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC: O(2^N)
//SC: O(N)

class Solution {
public:
    int dfs(int i, int n, vector<int>&nums){
        if(i>=n){
            return 0;
        }
        int left = dfs(i+1,n,nums);
        int right = nums[i] + dfs(i+2,n,nums);
        return max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>arr1,arr2;
        for(int i = 0;i<n;i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i != n-1){
                arr2.push_back(nums[i]);
            }
        }
        return max(dfs(0,n-1,arr1),dfs(0,n-1,arr2));
        
    }
};


//2.Optimized: memoization
//TC: O(N)
//SC: O(N) + stack o(N)

class Solution {
public:
    int dfs(int i, int n, vector<int>&nums,vector<int>&dp){
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
        if(n == 1){
            return nums[0];
        }
        vector<int>dp1(n+2,-1),dp2(n+2,-1);
        vector<int>arr1,arr2;
        for(int i = 0;i<n;i++){
            if(i!= 0){
                arr1.push_back(nums[i]);
            }
            if(i != n-1){
                arr2.push_back(nums[i]);
            }
        }
        return max(dfs(0,n-1,arr1,dp1),dfs(0,n-1,arr2,dp2));
        
    }
};

//3.Optimized: tabulation
//TC: O(N)
//SC: O(N) 

class Solution {
public:
    int dfs(int i, int n, vector<int>&nums,vector<int>&dp){
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
        if(n == 1){
            return nums[0];
        }
        vector<int>dp1(n+2,0),dp2(n+2,0);
        vector<int>arr1,arr2;
        for(int i = 0;i<n;i++){
            if(i!= 0){
                arr1.push_back(nums[i]);
            }
            if(i != n-1){
                arr2.push_back(nums[i]);
            }
        }
        for(int i = n-2; i>=0 ; i--){
            int left = dp1[i+1];
            int right = arr1[i] + dp1[i+2];
            dp1[i] = max(left,right);
        }
        for(int i = n-2; i>=0 ; i--){
            int left = dp2[i+1];
            int right = arr2[i] + dp2[i+2];
            dp2[i] = max(left,right);
        }
        return max(dp1[0],dp2[0]);
        
    }
};

//4.Space Optimized
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int dfs(int i, int n, vector<int>&nums,vector<int>&dp){
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
        if(n == 1){
            return nums[0];
        }
        int next1 = 0,next12 = 0,next2 = 0,next22 = 0;
        vector<int>arr1,arr2;
        for(int i = 0;i<n;i++){
            if(i!= 0){
                arr1.push_back(nums[i]);
            }
            if(i != n-1){
                arr2.push_back(nums[i]);
            }
        }
        for(int i = n-2; i>=0 ; i--){
            int left = next1;
            int right = arr1[i] + next12;
            int curr = max(left,right);
            next12 = next1;
            next1 = curr;
        }
        for(int i = n-2; i>=0 ; i--){
            int left = next2;
            int right = arr2[i] + next22;
            int curr = max(left,right);
            next22 = next2;
            next2 = curr;
        }
        return max(next1,next2);
        
    }
};