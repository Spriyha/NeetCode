// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

//1.bruteForce
//TC:O(N^2)
//sc:o(1)

#include<iostream>
#include<stdbits/c++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
        int rg = 0;
        int lg = 0;
            for(int j = i+1;j<n;j++){
                if(height[j]>rg){
                rg= height[j];
                }
            }
            for(int j = i-1;j>=0;j--){
                if(height[j]>lg) {
                lg = height[j];
                }
            }
            int x = min(rg,lg) - height[i];
            if(x>0){
                ans += x;
            }
        }
        return ans;
    }
};

//2.optimized
//TC: o(n)
//SC: o(n)+o(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>rg(n,0);
        vector<int>lg(n,0);
        int ans = 0;
        int x = 0;
        int y = 0;
        for(int i = 0; i<n;i++){
            lg[i]=x;
            if(height[i]>x){
                x=height[i];
            }
        }
        for(int i = n-1;i>=0;i--){
            rg[i]=y;
            if(height[i]>y){
                y=height[i];
            }
        }
        for(int i = 0;i<n;i++){
            int val = min(lg[i],rg[i])-height[i];
            if(val>0){
                ans += val;
            }  
        }
        return ans;
    }
};

//3.MoreOptimized
//TC:O(N)
//SC:O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>rg(n,0);
        int ans = 0;
        int x = 0;
        int y = 0;
        for(int i = n-1;i>=0;i--){
            if(height[i]>y){
                y=height[i];
            }
            rg[i]=y;
        }
        for(int i = 0;i<n;i++){
            if(height[i]>x){
                x=height[i];
            }
            int val = min(x,rg[i])-height[i];
            ans += val;
        }
        return ans;
    }
};