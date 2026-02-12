// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Example 5:
// Input: s = "([)]"
// Output: false

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
 
#include<iostream>
#include<std/bitsc++.h>
using namespace std;

//1.Optimized
//TC:O(N)
//SC:O(N)

class Solution {
public:
    bool isValid(string s) {
      int n = s.size();
      stack<char>st;
      for(int i = 0;i<n;i++){
        if(s[i]=='('|| s[i]=='{'||s[i]=='[' ){
            st.push(s[i]);
        }
        else{
            if(!st.empty()&& ((st.top()=='('&& s[i]==')') || (st.top()=='['&& s[i]==']')||(st.top()=='{'&& s[i]=='}'))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
      }
      if(st.empty()){
        return true;
      }
      else {
        return false;
      }  
    }
};

