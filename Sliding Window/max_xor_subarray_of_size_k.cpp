// Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
// Output: 15
// Explanation: arr[0] ^ arr[1] ^ arr[2] = 15, which is maximum.

// Input: arr[] = [1, 2, 4, 5, 6] , k = 2
// Output: 6
// Explanation: arr[1] ^ arr[2] = 6, which is maximum.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ k ≤ arr.size()


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Approach1
//Brute Force
//TC : O(N^2)
//SC : O(1)
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i = 0; i< n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum = sum ^ arr[j];
                if((j-i+1)==k){
                    res = max(res,sum);
                }
            }
        }
     
        return res;
    }
};

//Approach2 
//Optimized Sliding Window
//TC : O(n)
//SC : O(1)
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0;
        int res = 0;
        while(j<n){
            sum ^= arr[j];
            if((j-i+1)<k)
            {
                j++;
            }
            else {
                res = max(res,sum);
                sum ^= arr[i];
                i++;
                j++;
            }
        }
        return res;
    }
};