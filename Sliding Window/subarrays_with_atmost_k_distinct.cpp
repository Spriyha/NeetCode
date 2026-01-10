// You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

// Note: A subarray is a contiguous part of an array.

// Examples:

// Input: arr[] = [1, 2, 2, 3], k = 2
// Output: 9
// Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
// Input: arr[] = [1, 1, 1], k = 1
// Output: 6
// Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
// Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
// Output: 24
// Explanation: There are 24 subarrays with at most 2 distinct elements.
// Constraints:
// 1 ≤ arr.size() ≤ 2*104
// 1 ≤ k ≤ 2*104
// 1 ≤ arr[i] ≤ 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC:O(N^2)
//SC:O(1)

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            map<int,int>freq;
            for(int j=i;j<n;j++){
                freq[arr[j]]++;
                if(freq.size()<=k){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//2optimized 
//tc : o(n)
//sc : o(n)

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int ans = 0;
        map<int,int>freq;
        while(j<n){
            freq[arr[j]]++;
            if(freq.size()<=k){
                ans += j-i+1;
                j++;
            }
            else{
                while(freq.size()>k && i<=j){
                    freq[arr[i]]--;
                    if(freq[arr[i]] == 0){
                        freq.erase(arr[i]);
                    }
                    i++;
                }
                if(freq.size()==k){
                    ans += j-i+1;
                }
                j++;
            }
        }
        return ans;
    }
};

