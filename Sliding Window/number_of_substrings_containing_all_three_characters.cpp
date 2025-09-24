// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

// Example 3:
// Input: s = "abc"
// Output: 1

// Constraints:
// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

// 1.BruteForce
// TC : O(N^2)
// SC : O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int a = 0, b = 0, c = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'a')
                {
                    a = 1;
                }
                else if (s[j] == 'b')
                {
                    b = 1;
                }
                else
                {
                    c = 1;
                }
                if (a && b && c)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
