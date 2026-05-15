// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Example 1:
// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Example 2:
// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 

// Constraints:
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

//1.bruteForce
//TC: O(2^n)
//SC: O(N)


class Solution {
public:
    int dfs(int i, int n, vector<int>& cost ){
        if(i>=n){
            return 0;
        }
        int left = dfs(i+1,n,cost) + cost[i];
        int right = dfs(i+2,n,cost)+ cost[i];
        return min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(dfs(0,n,cost),dfs(1,n,cost));
    }
};



//2.Optimized: Memoization
//TC: O(N)
//SC: O(N) + Stack O(N)


class Solution {
public:
    int dfs(int i, int n, vector<int>& cost,vector<int>& dp ){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,cost,dp) + cost[i];
        int right = dfs(i+2,n,cost,dp)+ cost[i];
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+2,-1);
        return min(dfs(0,n,cost,dp),dfs(1,n,cost,dp));
    }
};

//3.Optimized: Tabulation
//TC: O(N)
//SC: O(N)

class Solution {
public:
    int dfs(int i, int n, vector<int>& cost,vector<int>& dp ){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,cost,dp) + cost[i];
        int right = dfs(i+2,n,cost,dp)+ cost[i];
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+2,0);
        for(int i = n-1;i>=0;i--){
            int left = dp[i+1] + cost[i];
            int right = dp[i+2]+ cost[i];
            dp[i] = min(left,right);
        }
        return min(dp[0],dp[1]);
    }
};

//4.Space Optimized
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int dfs(int i, int n, vector<int>& cost,vector<int>& dp ){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = dfs(i+1,n,cost,dp) + cost[i];
        int right = dfs(i+2,n,cost,dp)+ cost[i];
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next = 0,next2 = 0;
        for(int i = n-1;i>=0;i--){
            int left = next + cost[i];
            int right = next2 + cost[i];
            int curr = min(left,right);
            next2 = next;
            next = curr;
        }
        return min(next,next2);
    }
};
