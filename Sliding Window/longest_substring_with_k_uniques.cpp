// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.
// Note : If no such substring exists, return -1. 

// Examples:
// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.

// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

// Constraints:
// 1 ≤ s.size() ≤ 105
// 1 ≤ k ≤ 26

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce 
//TC : O(N^2)
//SC : O(1)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int res = 0;
        for(int i = 0 ; i< n;i++){
            map<char,int>freq;
            for(int j = i;j<n ;j++){
                freq[s[j]]++;
                if(freq.size()==k){
                    res = max(res,(j-i+1));
                }
            }
        }
        return res == 0 ? -1 : res;
    }
};

