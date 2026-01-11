// You are given two strings, s1 and s2. Your task is to find the smallest substring in s1 such that s2 appears as a subsequence within that substring.

// The characters of s2 must appear in the same sequence within the substring of s1.
// If there are multiple valid substrings of the same minimum length, return the one that appears first in s1.
// If no such substring exists, return an empty string.
// Note: Both the strings contain only lowercase english letters.

// Examples:
// Input: s1 = "geeksforgeeks", s2 = "eksrg"
// Output: "eksforg"
// Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is smallest and leftmost among all possible valid substrings of s1.

// Input: s1 = "abcdebdde", s2 = "bde" 
// Output: "bcde"
// Explanation:  "bcde" and "bdde" are two substring of s1 where s2 occurs as subsequence but "bcde" occur first so we return that.

// Input: s1 = "ad", s2 = "b" 
// Output: ""
// Explanation: There is no substring exists.

// Constraints:
// 1 ≤ s1.length ≤ 104
// 1 ≤ s2.length ≤ 50

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^3)
//SC : O(1)

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        string ans = "";
        int minlen = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                string s = s1.substr(i,j-i+1);
                int k=0,l=0;
                while(k<s.size()&&l<m){
                    if(s[k]==s2[l]){
                        k++;
                        l++;
                    }
                    else{
                        k++;
                    }
                }
                if(l==m && (j-i+1)<minlen){
                    ans = s;
                    minlen = j-i+1;
                }
            }
        }
        return ans;
    }
};

//Optimized
//TC : O(N^2)
//SC : O(1)
class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        string ans = "";
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[0]) {
                int p1 = i, p2 = 0;
                while (p1 < n && p2 < m) {
                    if (s1[p1] == s2[p2]) p2++;
                    p1++;
                }
                if (p2 == m) {
                    int end = p1 - 1; 
                    p2 = m - 1;
                    while (end >= i) {
                        if (s1[end] == s2[p2]) p2--;
                        if (p2 < 0) break;
                        end--;
                    }
                    int start = end;
                    int len = p1 - start;
                    if (len < minLen) {
                        minLen = len;
                        ans = s1.substr(start, len);
                    }
                }
            }
        }
        return ans;
    }
};