#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int cap, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        // vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=cap;j++){
        //         int nt=dp[i-1][j];
        //         int t=(j-wt[i-1]>=0)?val[i-1]+dp[i-1][j-wt[i-1]]:0;
        //         dp[i][j]=max(t,nt);
        //     }
        // }
        // return dp[n][cap];
        
        // space optimization
        vector<int>prev(cap+1,0);
        // prev[j]->dp[i-1][j]
        // curr[j]->dp[i][j]
        for(int i=1;i<=n;i++){
            vector<int>curr(cap+1,0);
            for(int j=0;j<=cap;j++){
                int nt=prev[j];
                int t=(j-wt[i-1]>=0)?val[i-1]+prev[j-wt[i-1]]:0;
                curr[j]=max(t,nt);
            }
            prev=curr;
        }
        return prev.back();
    }
};