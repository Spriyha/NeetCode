// Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to perform at most k operations.  In each operation, you can change any character of the string to any other uppercase English letter.

// Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most k such operations.

// Examples:

// Input: s = "ABBA", k = 2 
// Output: 4 
// Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.
// Input: s = "ADBD", k = 1
// Output: 3
// Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.
// Constraints:
// 1 ≤ n, k ≤ 105
// s consists of only uppercase English letters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//1.BruteForce
//TC: o(n^2)
//SC: o(n)

class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            map<char,int>freq;
            int maxfreq = 0;
            for(int j = i;j<n;j++){
                freq[s[j]]++;
                for(auto it : freq){
                    maxfreq = max(maxfreq,it.second);
                }
                if((j-i+1)-maxfreq <= k){
                    ans = max(ans,(j-i+1));
                }
                
            }
            
        }
        return ans;
        
    }
};




//2.Optimized
//TC: o(n)
//SC: o(n)



class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int i  = 0;
        int j = 0;
        map<char,int>freq;
        int ans = 0;
        int maxfreq = 0;
        while(j<n){
            freq[s[j]]++;
            for(auto it : freq){
                maxfreq = max(maxfreq,it.second);
            }
            if((j-i+1) - maxfreq <= k){
                ans = max(ans,(j-i+1)); 
                j++;
            }
            else{
                while((j-i+1) - maxfreq > k){
                    freq[s[i]]--;
                    if(freq[s[i]] == 0){
                        freq.erase(s[i]);
                    }
                    i++;
                }
                 ans = max(ans,(j-i+1));
                 j++;
            }
        }
        return ans;
    }
};