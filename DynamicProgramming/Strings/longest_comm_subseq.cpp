// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC: O(2^N)
//SC: O(N)

class Solution {
public:
    int dfs(int i, int j,string text1,string text2,int n, int m){
        if(i == n || j == m){
            return 0;
        }
        int length = 0;
        if(text1[i] == text2[j]){
            length = 1 + dfs(i+1,j+1,text1,text2,n,m);
        }
        else{
            length = max(dfs(i+1,j,text1,text2,n,m),dfs(i,j+1,text1,text2,n,m));
        }
        return length;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
       return dfs(0,0,text1,text2,n,m); 
    }
};


//2.Memoization
//TC: O(N*M)
//SC: O(N*M) + O(max(N,M))


class Solution {
public:
    int dfs(int i, int j,string text1,string text2,int n, int m,vector<vector<int>>& dp){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int length = 0;
        if(text1[i] == text2[j]){
            length = 1 + dfs(i+1,j+1,text1,text2,n,m,dp);
        }
        else{
            length = max(dfs(i+1,j,text1,text2,n,m,dp),dfs(i,j+1,text1,text2,n,m,dp));
        }
        return dp[i][j] = length;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return dfs(0,0,text1,text2,n,m,dp); 
    }
};

//3.Tabulation
//TC: O(N*M)
//SC: O(N*M)

class Solution {
public:
    int dfs(int i, int j,string text1,string text2,int n, int m,vector<vector<int>>& dp){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int length = 0;
        if(text1[i] == text2[j]){
            length = 1 + dfs(i+1,j+1,text1,text2,n,m,dp);
        }
        else{
            length = max(dfs(i+1,j,text1,text2,n,m,dp),dfs(i,j+1,text1,text2,n,m,dp));
        }
        return dp[i][j] = length;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int length = 0;
                if(text1[i] == text2[j]){
                    length = 1 + dp[i+1][j+1];
                }
                else{
                    length = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = length;
            }
        }
       return dp[0][0]; 
    }
};

//4.Space Optimized
//TC: O(N*M)
//SC: O(M)

class Solution {
public:
    int dfs(int i, int j,string text1,string text2,int n, int m,vector<vector<int>>& dp){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int length = 0;
        if(text1[i] == text2[j]){
            length = 1 + dfs(i+1,j+1,text1,text2,n,m,dp);
        }
        else{
            length = max(dfs(i+1,j,text1,text2,n,m,dp),dfs(i,j+1,text1,text2,n,m,dp));
        }
        return dp[i][j] = length;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>curr(m+1,0),next(m+1,0);
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int length = 0;
                if(text1[i] == text2[j]){
                    length = 1 + next[j+1];
                }
                else{
                    length = max(next[j],curr[j+1]);
                }
                curr[j] = length;
            }
            next = curr;
        }
       return next[0]; 
    }
};