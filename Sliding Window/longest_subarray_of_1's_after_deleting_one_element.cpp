// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0 ;i<n;i++){
            int count = 0;
            for(int j = i; j<n;j++){
                if(nums[j]==0){
                    count++;
                }
                if(count<=1){
                    res = max(res,j-i);
                }
            }
        }
        return res;
    }
};