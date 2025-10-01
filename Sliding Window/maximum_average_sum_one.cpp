// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

// Constraints:
// n == nums.length
// 1 <= k <= n <= 105
// -104 <= nums[i] <= 104
 
//1.BruteForce
//TC : O(N^2)
//SC : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double res = INT_MIN;
        for(int i = 0;i<n;i++){
            double avg = 0;
            for(int j = i;j<n;j++){
                avg = avg + nums[j];
                if((j-i+1)==k){
                    res = max((avg/k),res);
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
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;
        double avg = 0;
        double res = INT_MIN;
        while(j<n){
            avg += nums[j];
            if((j-i+1)<k){
                j++;
            }
            else if ((j-i+1)==k){
                res = max((avg/k),res);
                avg -= nums[i];
                i++;
                j++;
            }
        }
        return res;
    }
};
