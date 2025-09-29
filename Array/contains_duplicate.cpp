// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true
// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation:
// All elements are distinct.

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

 
// Constraints:
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

//1.BruteForce
//TC -- o(n^2)
//SC -- o(1) because of variables n,a,i,j
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        int a;
        for(int i = 0;i<n-1;i++){
            a = nums[i];
            for(int j = i+1;j<n;j++){
            if(a==nums[j])
            {
                return true;
            }
         }
        }
        return false;
    }
};


//2.Optimized 
//Tc -- sort of array > o(nlogn),loop > o(n) so total >>> o(nlogn)
//SC -- depends on sort algo being used

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i<n-1;i++){
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }    
};

//3.Optimized
//Tc -- o(n)
//SC -- o(n)
#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;
        for(int i = 0;i< n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};