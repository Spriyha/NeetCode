// Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.

// Examples:
// Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
// Output: [3, 3, 4, 5, 5, 5, 6]
// Explanation: 
// 1st contiguous subarray [1, 2, 3], max = 3
// 2nd contiguous subarray [2, 3, 1], max = 3
// 3rd contiguous subarray [3, 1, 4], max = 4
// 4th contiguous subarray [1, 4, 5], max = 5
// 5th contiguous subarray [4, 5, 2], max = 5
// 6th contiguous subarray [5, 2, 3], max = 5
// 7th contiguous subarray [2, 3, 6], max = 6

// Input: arr[] = [5, 1, 3, 4, 2], k = 1
// Output: [5, 1, 3, 4, 2]
// Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ k ≤ arr.size()
// 0 ≤ arr[i] ≤ 109

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>res;
        for(int i = 0;i<n;i++){
            int maxi = 0;
            for(int j = i ; j<n;j++){
                   maxi = max(maxi,arr[j]);
                   if((j-i+1)==k){
                      res.push_back(maxi);
                     }
            }
           
        }
        return res;
    }
};

//2.Optimized 
//TC : O(N)
//SC : O(N)


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0 ,j = 0;
        vector<int>res;
        deque<int>deq;
        while(j<n){
          while(!deq.empty() && deq.back()<arr[j]){
              deq.pop_back();
          }
          deq.push_back(arr[j]);
          if((j-i+1)<k){
              j++;
          }
          else if ((j-i+1)==k){
              res.push_back(deq.front());
              if(deq.front()==arr[i]){
                  deq.pop_front();
              }
              i++;
              j++;
          }
        }
        return res;
    }
};