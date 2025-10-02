// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

// Example 1:
// Input: txt = "forxxorfxdofr", pat = "for"
// Output: 3
// Explanation: for, orf and ofr appears in the txt, hence answer is 3.

// Example 2:
// Input: txt = "aabaabaa", pat = "aaba"
// Output: 4
// Explanation: aaba is present 4 times in txt.

// Constraints:
// 1 <= |pat| <= |txt| <= 105
// Both strings contain lowercase English letters.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1.BruteForce
//TC : O(N^3)
//SC : O(N)

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        int m = pat.size();
        int count = 0 ;
        for(int i = 0;i<n;i++){
            map<int,int>freq;
            for(int j = i;j<n;j++){
                freq[txt[j]]++;
                if((j-i+1)==m){
                    for(int k = 0;k<m;k++){
                        freq[pat[k]]--;
                    }
                    int flag = 1;
                    for(auto it : freq){
                        if(it.second != 0){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                       count++; 
                    }
                }
            }
        }
        return count;
    }
};

//2.solution ,still TC is O(N^3) but reduces number of operation for calculating frequency of pattern
//SC : O(N)


class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        int m = pat.size();
        int count = 0 ;
        map<int,int>freq2;
        for(int k = 0;k<m;k++){
            freq2[pat[k]]++;
        }
        for(int i = 0;i<n;i++){
            map<int,int>freq;
            for(int j = i;j<n;j++){
                freq[txt[j]]++;
                if((j-i+1)==m){
                    
                    int flag = 1;
                    for(auto it : freq){
                        if((it.second != freq2[it.first])){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                       count++; 
                    }
                }
            }
        }
        return count;
    }
};