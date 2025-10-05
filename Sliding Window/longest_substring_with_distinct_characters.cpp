// You are given a string s. You have to find the length of the longest substring with all distinct characters. 

// Examples:
// Input: s = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest substring with all distinct characters.

// Input: s = "aaa"
// Output: 1
// Explanation: "a" is the longest substring with all distinct characters.

// Input: s = "abcdefabcbb"
// Output: 6
// Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.

// Constraints:
// 1 ≤ s.size() ≤ 105
// s consists of lowercase english letters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N) 
//SC : O(N)

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            map<char,int>freq;
            for(int j = i; j<n; j++){
                freq[s[j]]++;
                if(freq.size()==(j-i+1)){
                    res = max(res,(j-i+1));
                }
            }
        }
        return res;
    }
};
