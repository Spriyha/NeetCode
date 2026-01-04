// You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

// Note:
// The array follows 0-based indexing.
// The number of rows and columns in the array are denoted by n and m respectively.

// Examples:
// Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
// Output: 2
// Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

// Input: arr[][] = [[0,0], [1,1]]
// Output: 1
// Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

// Input: arr[][] = [[0,0], [0,0]]
// Output: -1
// Explanation: No row contains any 1s, so the output is -1.

// Constraints:
// 1 ≤ arr.size(), arr[i].size() ≤ 103
// 0 ≤ arr[i][j] ≤ 1 

//Approch 1 
// Brute Force 
//TC = O(N*M)
//SC = O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = INT_MAX ;
        int n = arr.size();
        int m = arr[0].size();
        
        int maxCount = 0;
        for(int i = 0; i<n;i++){
            int count = 0;
            for(int j = 0; j< m; j++){
                if (arr[i][j]==1){
                    count++;
                }
            }
            if(count > maxCount){
                ans = i;
                maxCount = count;
            }
        }
        return ans == INT_MAX ? -1:ans;
        
    }
};

//Approach 2
//Binary Search 
//TC : O(NlogM)
//Sc : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int findCountOf1s(int i,int m,vector<vector<int>> &arr){
        int s = 0, e = m - 1;
        int index = m;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[i][mid]==1){
                index = mid;
                e = mid - 1;
            }
            else{
                s= mid + 1;
            }
        }
        return m - index;
        
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = INT_MAX ;
        int n = arr.size();
        int m = arr[0].size();
        
        int maxCount = 0;
        for(int i = 0; i<n;i++){
            int count = findCountOf1s(i,m,arr);
            if(count > maxCount){
                ans = i;
                maxCount = count;
            }
        }
        return ans == INT_MAX ? -1:ans;
        
    }
};


//Approach 3 
//Optimized
//TC : O(N+M)
//SC : O(1)

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1;
        int n = arr.size();
        int m = arr[0].size();
        int i = 0;
        int j = m -1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                ans = i;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};