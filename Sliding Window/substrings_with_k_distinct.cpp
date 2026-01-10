// You are given a string s consisting of lowercase characters and an integer k, You have to count all possible substrings that have exactly k distinct characters.

// Examples :
// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]

// Input: s = "aba", k = 2
// Output: 3
// Explanation: Possible substrings are ["ab", "ba", "aba"]

// Input: s = "aa", k = 1
// Output: 3
// Explanation: Possible substrings are ["a", "a", "aa"]

// Constraints:
// 1 ≤ s.size() ≤ 106
// 1 ≤ k ≤ 26

#include<iostrem>
#include<bits/c++.h>
using namspaces std;

//1.BruteForce
//TC: O(N^2)
//SC: O(1)


class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            map<char,int>freq;
            for(int j = i;j<n;j++){
                freq[s[j]]++;
                if(freq.size()==k){
                    count++;
                }
            }
        }
        return count;
    }
};

//2.optimized
//TC: O(N)
//SC : O(N)
class Solution {
  public:
    int count(string& s,int k){
        int i = 0,j = 0;
        int n = s.size();
        int count = 0;
        map<char,int>freq;
        while(j<n){
            freq[s[j]]++;
            if(freq.size()<k){
                j++;
            }
            else {
                while(freq.size()==k && i<=j){
                    count += n-j;
                    freq[s[i]]--;
                    if(freq[s[i]]==0){
                        freq.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        // code here
        return count(s,k)- count(s,k+1);
    }
};

//3.optimized
//TC: o(n)
//SC: o(26)

class Solution {
  public:
    int count(string& s,int k){
        int i = 0,j = 0;
        int n = s.size();
        int count = 0;
        int ans = 0;
        vector<int>freq(26,0);
        while(j<n){
            if(freq[s[j] -'a'] == 0 ){
                count++;
            }
            freq[s[j]-'a']++;
            if(count<k){
                j++;
            }
            else {
                while(count==k && i<=j){
                    ans += n-j;
                    freq[s[i]-'a']--;
                    if(freq[s[i]-'a']==0){
                        count--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        return count(s,k)- count(s,k+1);
    }
};