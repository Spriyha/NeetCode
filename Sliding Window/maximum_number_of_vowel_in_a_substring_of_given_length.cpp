// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Example 1:
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:
// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length
 
//1.BruteForce
//TC : O(N^2)
//SC  : O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = i ;j<n;j++){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    count++;
                }
                if((j-i+1)==k){
                    res = max (res,count);
                }
            }
        }
        return res;
    }
};


//2.Optimized
//TC : O(N)
//SC :O(1)

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0,j = 0;
        int count = 0;
        int res = 0;
        while(j<n){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                count++;
            }
            if((j-i+1)<k){
                j++;
            }
            else if ((j-i+1)==k){
                res = max(res,count);
               if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count--;
                
            }
            i++;
            j++;
            }
        }
        return res;
    }
};