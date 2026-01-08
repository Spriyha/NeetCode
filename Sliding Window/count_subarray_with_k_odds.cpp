// You are given an array arr[] of positive integers and an integer k. You have to count the number of subarrays that contain exactly k odd numbers.

// Examples:

// Input: arr[] = [2, 5, 6, 9], k = 2
// Output: 2
// Explanation: There are 2 subarrays with 2 odds: [2, 5, 6, 9] and [5, 6, 9].

// Input: arr[] = [2, 2, 5, 6, 9, 2, 11], k = 2
// Output: 8
// Explanation: There are 8 subarrays with 2 odds: [2, 2, 5, 6, 9], [2, 5, 6, 9], [5, 6, 9], [2, 2, 5, 6, 9, 2], [2, 5, 6, 9, 2], [5, 6, 9, 2], [6, 9, 2, 11] and [9, 2, 11].

// Constraint:
// 1 ≤ k ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 109

//1.BruteForce
//Tc: o(n^2)
//sc : O(1)

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i = 0 ; i<n;i++){
            int count = 0;
            for(int j = i; j< n ; j++){
                if(arr[j] % 2 != 0){
                    count++;
                }
                if(count == k ){
                    ans++;
                }
            }
        }
        return ans;
    }
};