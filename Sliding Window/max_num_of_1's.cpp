// Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

// Examples:
// Input: arr[] = [1, 0, 1], k = 1
// Output: 3
// Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.

// Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
// Output: 5
// Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.

// Input: arr[] = [1, 1], k = 2
// Output: 2
// Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ k ≤ arr.size()
// 0 ≤ arr[i] ≤ 1

#include<iostream>
#include<stdbits/c++.h>
using namespace std;

//1.bruteforce
//TC: O(N^2)
//SC: O(1)

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = i; j<n;j++){
                if(arr[j]==0){
                    count++;
                }
                if(count<=k){
                    ans = max(ans,(j-i+1));
                }
            }
           
        }
         return ans;
    }
};

//2.optimized
//TC: O(N)
//SC: O(1)


class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int ans = 0;
        int count = 0;
        while(j<n){
            if(arr[j]==0){
                count++;
            }
            if(count <= k){
                ans = max(ans,(j-i+1));
                j++;
            }
            else {
                while(count>k){
                    if(arr[i]==0){
                        count--;
                    }
                    i++;
                }
                if(count == k){
                    ans = max(ans,(j-i+1));
                }
                j++;
            }
        }
        return ans;
        
    }
};

