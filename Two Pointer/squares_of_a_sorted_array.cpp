// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 
// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i = 0 ; i<n;i++){
            res[i]= nums[i]*nums[i];
        }
        sort(res.begin(),res.end());
        return res;
    }
};


//2.TwoPointer
//TC : O(N)
//SC : O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ,j = n-1;
        vector<int>res;
        while(i<=j){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if(a<b){
                res.push_back(b);
                j--;
            }
            else{
                res.push_back(a);
                i++;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ,j = n-1;
        int k = n-1;
        vector<int>res(n);
        while(i<=j){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if(a<b){
                res[k]=b;
                j--;
            }
            else{
               res[k]=a;
                i++;
            }
            k--;
        }
        return res;
    }
};