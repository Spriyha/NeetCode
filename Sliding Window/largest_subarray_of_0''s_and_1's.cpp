// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

// Examples:
// Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
// Output: 6
// Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

// Input: arr[] = [0, 0, 1, 1, 0]
// Output: 4
// Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.

// Input: arr[] = [0]
// Output: 0
// Explnation: There is no subarray with an equal number of 0s and 1s.

// Constraints:
// 1 <= arr.size() <= 105
// 0 <= arr[i] <= 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std:

//1.brute force 
//TC: O(N^2)
//SC: O(1)

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int count0 = 0;
            int count1 = 0;
            for(int j=i;j<n;j++){
               if(arr[j]==0){
                   count0++;
               }
               else{
                   count1++;
               }
               if(count1==count0){
                   ans = max(ans,(j-i+1));
               }
            }
        }
        return ans;
    }
};

//Single variable brute force 
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int count  = 0;
            for(int j = i;j<n;j++){
                if(arr[j]==0){
                    count++;
                }
                else{
                    count--;
                }
                if(count == 0){
                    res = max(res,(j-i+1));
                }
            }
        }
        return res;
        
    }
};







//2.Optimized
//TC: o(N)
//SC: O(N)



class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int res = 0;
        int sum = 0;
        map<int,int>mp;
        mp[0] = -1;
        for(int i = 0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
             sum += arr[i];
            if(mp.find(sum)!=mp.end()){
                res = max(res,(i-mp[sum]));
            }
            else{
                mp[sum]=i;
            }
        }
        return res;
    }
};