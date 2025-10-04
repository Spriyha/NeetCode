// Given an array arr and an integer k. You have to find the maximum product of k contiguous elements in the array. 

// Examples:
// Input: arr[] = [1, 2, 3, 4] and k = 2
// Output: 12 
// Explanation: The sub-array of size 2 will be 3 4 and the product is 12.

// Input: arr[] = [1, 6, 7, 8] and k = 3
// Output: 336
// Explanation: The sub-array of size 3 will be 6 7 8 and the product is 336.

// Expected Time Complexity: O(n)
// Expected Auxilary Space: O(1)

// Constraints:
// 1 <= arr.size() <= 106
// 1 <= k<= 8
// 1<= arr[i] <=102


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    int findMaxProduct(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int prod = 1;
            for(int j = i ;j<n;j++){
                prod *= arr[j];
                if((j-i+1)== k){
                    res = max(res,prod);
                }
            }
        }
        return res;
    }
};

//2.Optimized
//TC : O(N)
//SC : O(1)


/*You are required to complete the function*/
class Solution {
  public:
    int findMaxProduct(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0 , j= 0;
        int prod = 1;
        int res = 0;
        while(j<n){
            prod *= arr[j];
            if((j-i+1)<k){
                j++;
            }
            else if ((j-i+1)==k){
                res = max(prod,res);
                prod /= arr[i];
                i++;
                j++;
                
            }
        }
        return res;
    }
};