// You are given an integer array arr[]. The value of a subarray is defined as the bitwise XOR of all elements in that subarray.
// Your task is to compute the bitwise XOR of the values of all possible subarrays of arr[].

// Examples:

// Input: arr[] = [1, 2, 3] 
// Output: 2
// Explanation:
// xor[1] = 1
// xor[1, 2] = 3
// xor[2, 3] = 1
// xor[1, 2, 3] = 0
// xor[2] = 2
// xor[3] = 3
// Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2

// Input: arr[] = [1, 2]
// Output: 0
// Explanation:
// xor[1] = 1
// xor[1, 2] = 3
// xor[2] = 2
// Result : 1 ^ 3 ^ 2 = 0

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//TC : O(N^2)
//SC : O(1)


class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int xr = 0;
            for(int j = i ; j<n;j++){
                xr = xr ^ arr[j];
                res = res ^ xr;
            }
        }
        return res;
    }
};
//2.Optimized
//TC : O(N)
//SC :O(1)


class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0 ;
        for(int i = 0;i<n;i++){
            if(((i+1) & 1) && ((n-i) & 1)){
                res ^= arr[i];
            }
        }
        return res;
    }
};