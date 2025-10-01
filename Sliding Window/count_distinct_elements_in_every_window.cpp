// Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

// Examples:
// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output: [3, 4, 4, 3]
// Explanation:
// First window is [1, 2, 1, 3], count of distinct numbers is 3.
// Second window is [2, 1, 3, 4] count of distinct numbers is 4.
// Third window is [1, 3, 4, 2] count of distinct numbers is 4.

// Fourth window is [3, 4, 2, 3] count of distinct numbers is 3.
// Input: arr[] = [4, 1, 1], k = 2
// Output: [2, 1]
// Explanation:
// First window is [4, 1], count of distinct numbers is 2.
// Second window is [1, 1], count of distinct numbers is 1.

// Input: arr[] = [1, 1, 1, 1, 1], k = 3
// Output: [1, 1, 1]
// Explanation: Every window of size 3 in the array [1, 1, 1, 1, 1], contains only the element 1, so the number of distinct elements in each window is 1.

// Constraints:
// 1 ≤ k ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            map<int,int>freq;
            for(int j = i;j<n;j++){
                freq[arr[j]];
                if((j-i+1)== k){
                    ans.push_back(freq.size());
                }
            }
        }
        return ans;
    }
};


//2.Optimized
//TC : O(N)
//SC  : O(N)

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int i = 0,j=0;
        vector<int>ans;
        map<int,int>freq;
        while(j<n){
            freq[arr[j]]++;
            if((j-i+1)<k){
                j++;
            }
            else if ((j-i+1)==k){
                ans.push_back(freq.size());
                freq[arr[i]]--;
                if(freq[arr[i]]== 0){
                    freq.erase(arr[i]);
                }
                i++;
                j++;
                
            }
        }
        return ans;
    }
};