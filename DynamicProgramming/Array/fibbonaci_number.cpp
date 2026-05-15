// Find the n-th Fibonacci number for a given non-negative integer n.
// The Fibonacci sequence is defined as:

// F(0) = 0
// F(1) = 1
// F(n) = F(n - 1) + F(n - 2) for n ≥ 2
// Examples :

// Input: n = 5
// Output: 5
// Explanation: The 5th Fibonacci number is 5.
// Input: n = 0
// Output: 0 
// Explanation: The 0th Fibonacci number is 0.
// Input: n = 1
// Output: 1
// Explanation: The 1st Fibonacci number is 1.
// Constraints:
// 0 ≤ n ≤ 30

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce:Recursion
//TC: o(n^2)
//SC: O(N)

class Solution {
  public:
    int dfs(int n){
        if(n == 0 || n == 1 ){
            return n;
        }
        return dfs(n-1) + dfs(n-2);
    }
    int nthFibonacci(int n) {
        // code here
        return dfs(n);
    }
};


//2.Optimized: Memoization
//TC: O(N)
//SC: O(N) + Stackspace O(N)

class Solution {
  public:
    int dfs(int n,vector<int>&dp){
        if(n == 0 || n == 1 ){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = dfs(n-1,dp) + dfs(n-2,dp);
        
    }
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return dfs(n,dp);
    }
};


//3.Optimized: Tabulation
//TC: O(N)
//SC: o(N)

class Solution {
  public:
    int dfs(int n,vector<int>&dp){
        if(n == 0 || n == 1 ){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = dfs(n-1,dp) + dfs(n-2,dp);
        
    }
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
             dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//4.Optimized : Space Optimized
//TC: O(N)
//SC: O(1)

class Solution {
  public:
    int dfs(int n,vector<int>&dp){
        if(n == 0 || n == 1 ){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = dfs(n-1,dp) + dfs(n-2,dp);
        
    }
    int nthFibonacci(int n) {
        // code here
        if(n == 0){
            return 0;
        }
        int prev = 1;
        int prev2 = 0;
        for(int i = 2; i<=n; i++){
             int curr = prev + prev2;
             prev2 = prev;
             prev = curr;
        }
        return prev;
    }
};
