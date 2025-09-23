// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array.

 

// Example 1:
// Input: nums = [1], k = 1
// Output: 1

// Example 2:
// Input: nums = [1,2], k = 4
// Output: -1

// Example 3:
// Input: nums = [2,-1,2], k = 3
// Output: 3
 
// Constraints:
// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// 1 <= k <= 109
 
//1,BruteForce
//TC : O(N^2)
//SC : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        for(int i = 0 ;i<n;i++){
            int sum = 0 ;
            for(int j = i; j<n;j++){
                sum = sum + nums[j];
                if(sum >= k){
                    res = min(res,j-i+1);
                }
            }
        }
        return res == INT_MAX ? -1 : res ;
    }
};