// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.Brute force
//TC: O(2^N)
//SC: O(N)

class Solution {
public:
    int dfs(int i , int j, string s, string r,int n){
        if(i == n || j == n){
            return 0;
        }
        if(s[i] == r[j]){
            return 1 + dfs(i+1,j+1,s,r,n);
        }
        else{
            return max(dfs(i,j+1,s,r,n),dfs(i+1,j,s,r,n));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        return dfs(0,0,s,r,n);
        
    }
};



//2.Memoization
//TC: O(N*N)
//SC: O(N) + O(N*N)

class Solution {
public:
    int dfs(int i , int j, string s, string r,int n,vector<vector<int>>& dp){
        if(i == n || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == r[j]){
            return dp[i][j] = 1 + dfs(i+1,j+1,s,r,n,dp);
        }
        else{
            return dp[i][j] = max(dfs(i,j+1,s,r,n,dp),dfs(i+1,j,s,r,n,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dfs(0,0,s,r,n,dp);
        
    }
};

//3.Tabulation
//TC: o(N*N)
//SC: o)(N*N)


class Solution {
public:
    int dfs(int i , int j, string s, string r,int n,vector<vector<int>>& dp){
        if(i == n || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == r[j]){
            return dp[i][j] = 1 + dfs(i+1,j+1,s,r,n,dp);
        }
        else{
            return dp[i][j] = max(dfs(i,j+1,s,r,n,dp),dfs(i+1,j,s,r,n,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(s[i] == r[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                     dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
        
    }
};


//4.Space Optimized
//TC: O(N*N)
//SC: O(N)

class Solution {
public:
    int dfs(int i , int j, string s, string r,int n,vector<vector<int>>& dp){
        if(i == n || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == r[j]){
            return dp[i][j] = 1 + dfs(i+1,j+1,s,r,n,dp);
        }
        else{
            return dp[i][j] = max(dfs(i,j+1,s,r,n,dp),dfs(i+1,j,s,r,n,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        vector<int>curr(n+1,0),next(n+1,0);
         for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(s[i] == r[j]){
                    curr[j] = 1 + next[j+1];
                }
                else{
                     curr[j] = max(curr[j+1],next[j]);
                }
            }
            next = curr;
        }
        return next[0];
        
    }
};




