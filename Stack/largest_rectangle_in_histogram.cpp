// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Input: heights = [2,4]
// Output: 4

// Constraints:
// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

#include<iostream>
#include<stdbits/c++.h>
using namespace std;

//1.Bruteforce
//TC:O(N^2)
//SC:O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int rj = n;
            for(int j = i+1;j<n;j++){
                if(heights[j]<heights[i]){
                    rj = j;
                    break;
                }
            }
            int lj = -1;
            for(int j = i-1;j>=0;j--){
                if(heights[j]<heights[i]){
                    lj = j;
                    break;
                }
            }
            ans = max(ans,(rj-lj-1)*heights[i]);
        }
        return ans;   
    }
};

//2.Optimized
//TC:o(n)
//sc:o(n)+o(n)+o(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int>rj(n,n);
        vector<int>lj(n,-1);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            lj[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            rj[i]=st.empty()?n:st.top();
            st.push(i);
        }
        for(int i = 0;i<n;i++){
            ans = max(ans,(rj[i]-lj[i]-1)*heights[i]);
        }
        return ans;   
    }
};