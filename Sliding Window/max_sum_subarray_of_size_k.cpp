// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
// Note: A subarray is a contiguous part of any given array.

// Examples:
// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.

// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ k ≤ arr.size()

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += arr[j];
                if((j-i+1)==k){
                    res = max(res,sum);
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
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i = 0,j = 0,ans = 0;
        int n = arr.size();
        int sum = 0;
        while(j<n){
            sum += arr[j];
            if((j-i+1)<k){
                j++;
            }
            else if ((j-i+1)==k){
                ans = max(ans,sum);
                sum -= arr[i];
                i++;
                j++;
            }
            
        }
        return ans;
    }
};
