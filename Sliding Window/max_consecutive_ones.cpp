// Given a binary array nums, return the maximum number of consecutive 1's in the array.

 
// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:
// Input: nums = [1,0,1,1,0,1]
// Output: 2
 
// Constraints:

// 1 <= nums.length <= 105

// nums[i] is either 0 or 1.

//1.BruteForce
//TC : o(n^2)
//SC : o(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i<n;i++){
            int count = 0 ;
            for(int j = i ; j<n ; j++){
                if(nums[j]==1){
                    count++;
                }
                if(count == (j-i+1)){
                    res = max(res,count);
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0,j=0;
        int n = nums.size();
        int res = 0;
        int count = 0;
        while(j<n){
            if(nums[j]==0){
                count++;
            }
            if(count == 0){
                res = max(res,(j-i+1));
                j++;
            }
            else{
                while(count > 0){
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
