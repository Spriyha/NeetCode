// A string is good if there are no repeated characters.
// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
// A substring is a contiguous sequence of characters in a string.

// Example 1:
// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
// The only good substring of length 3 is "xyz".

// Example 2:
// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".

// Constraints:
// 1 <= s.length <= 100
// s​​​​​​ consists of lowercase English letters.

// 1.BruteForce
// TC : O(N^2)
// SC : O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            char a = 'A', b = 'A', c = 'A';
            for (int j = i; j < n; j++)
            {
                if (a == 'A')
                {
                    a = s[j];
                }
                else if (b == 'A')
                {
                    b = s[j];
                }
                else
                {
                    c = s[j];
                }
                if ((j - i + 1) == 3 && a != b && b != c && a != c)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
