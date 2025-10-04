// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

// Examples:
// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].

// Constraints:
// 1 ≤ arr.size() ≤ 105
// -104 ≤ arr[i] ≤ 104
// -109 ≤ k ≤ 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += arr[j];
                if(sum == k){
                    res = max(res,(j-i+1));
                }
            }
        }
        return res;
    }
};


//2.Optimized - But only will work for positive integers
//TC : O(N^2)
//SC : O(1)


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int res = 0;
        int sum = 0;
        while(j<n){
            sum += arr[j];
            if(sum < k){
                j++;
            }
            else if (sum == k){
                res = max(res,(j-i+1));
                j++;
            }
            else if (sum > k){
                while((i <= j) && (sum > k)){
                    sum -= arr[i];
                    i++;
                }
                if(sum == k){
                    res = max(res,(j-i+1));
                }
                j++;
            }
        }
        return res;
    }
};

//3.Optimized
//TC : O(N) 
//SC : O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        int res = 0;
        map<int,int>mp;
        mp[0] = -1;
        for(int j = 0 ;j<n;j++){
            sum += arr[j];
            if(sum == k){
                res = max(res,(j+1));
            }
            int rem = sum - k ;
            if(mp.find(rem)!=mp.end()){
                res = max(res,j-mp[rem]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum] = j;
            }
        }
        return res;
    }
};