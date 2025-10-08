// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

// 1.BruteForce
// TC : O(N^2)
// SC :O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                {
                    count++;
                }
                if (count <= k)
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

//2.Optimized
//TC : O(N)
//SC : O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int res = 0;
        int count = 0;
        while(j<n){
            if(nums[j]==0){
                count++;
            }
            if(count <=k){
                res = max(res,(j-i+1));
                j++;
            }
            else{
                while(count > k){
                    if(nums[i]==0){
                        count--;
                    }
                    i++;
                }
                res = max(res,(j-i+1));
                j++;
            }
        }
        return res;
    }
};