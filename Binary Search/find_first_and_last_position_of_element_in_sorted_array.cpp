// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
 
// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N)
//SC : O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>res(2,-1);
        for(int i = 0; i< n;i++){
            if(nums[i]==target){
            res[0]=i;
             break;
            }
           
        }
        for(int j = n-1;j>=0;j--){
            if(nums[j]==target){
                res[1]=j;
                break;
            }
        }
        return res;
    }
};

//2.Instead of using 2 loops , calculated by 1 loop only
//TC : O(N)
//SC : O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>res(2,-1);
        for(int i = 0; i< n;i++){
            if(nums[i]==target){
                if(res[0]==-1){
                    res[0]=i;
                }
                res[1] = i;
            } 
        }
        return res;
    }
};

//3.Optimized 
//TC : O(logn)
//SC : O(1)

class Solution {

public:
    int firstIndex(vector<int>&arr,int &target){
        int n = arr.size();
        int s = 0, e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                e = mid - 1;
            }
            else if (arr[mid]>target){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int lastIndex(vector<int>&arr,int &target){
        int n = arr.size();
        int s = 0, e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(arr[mid]==target){
                ans = mid;
                s = mid + 1;
            }
            else if (arr[mid]>target){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>res(2,-1);
       res[0] = firstIndex(nums,target);
       res[1] = lastIndex(nums,target); 
       return res;
    }
};

 
