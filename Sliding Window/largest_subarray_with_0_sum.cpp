// Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.
// Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

// Examples:
// Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

// Input: arr[] = [2, 10, 4]
// Output: 0
// Explanation: There is no subarray with a sum of 0.

// Input: arr[] = [1, 0, -4, 3, 1, 0]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]

// Constraints:
// 1 ≤ arr.size() ≤ 106
// −103 ≤ arr[i] ≤ 103

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//1.bruteforce
//TC: O(n^2)
//SC: O(1)

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += arr[j];
                if(sum == 0){
                    ans = max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }
};


//2.Optimized
//TC: O(N)
//SC: O(N)

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        map<int,int>mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0;i<n;i++){
            sum += arr[i];
            if(mp.find(sum)!=mp.end()){
                ans = max(ans,(i-mp[sum]));
            }
            else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};