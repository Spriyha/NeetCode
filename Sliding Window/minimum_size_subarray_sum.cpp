// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 
// Constraints:
// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                if(sum  >= target){
                    res = min(res,j-i+1);
                }
            }
        }
        return res==INT_MAX ? 0 : res;
    }
};

//2.Optimized 
//TC : O(N)
//SC : O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0, i=0;
        int sum = 0;
        int res = INT_MAX;
        while(j<n){
            sum += nums[j];
            if(sum<target){
                j++;
            }
            else if (sum >= target){
                while(sum >= target){
                    res = min(res,(j-i+1));
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        return res == INT_MAX ? 0: res;
    }
};